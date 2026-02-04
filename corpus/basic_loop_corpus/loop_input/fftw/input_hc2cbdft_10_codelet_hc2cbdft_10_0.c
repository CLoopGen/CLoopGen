#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *Rp;
R *Ip;
R *Rm;
R *Im;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP951056516;
E KP587785252;
E KP250000000;
E KP559016994;
INT m;

static size_t data_size = 1 << 20; // ~8MB total (each array is 1MB of doubles)
static INT vector_size = 5;       // rs[4] is accessed, so we need at least 5 elements

void init_vars() {
    // Initialize constants
    KP951056516 = 0.9510565162951535;
    KP587785252 = 0.5877852522924731;
    KP250000000 = 0.25;
    KP559016994 = 0.5590169943749475;

    // Allocate arrays with sufficient size
    Rp = (R*)aligned_alloc(64, data_size * sizeof(R));
    Ip = (R*)aligned_alloc(64, data_size * sizeof(R));
    Rm = (R*)aligned_alloc(64, data_size * sizeof(R));
    Im = (R*)aligned_alloc(64, data_size * sizeof(R));
    W  = (R*)aligned_alloc(64, 18 * sizeof(R)); // W is indexed up to 17

    // Allocate and initialize stride vector
    rs = (stride)malloc(vector_size * sizeof(INT));
    for (INT i = 0; i < vector_size; ++i) {
        rs[i] = i; // simple unit stride for bounds safety
    }

    // Ensure that access like rs[4] is valid
    if (vector_size < 5) {
        fprintf(stderr, "Error: rs must have at least 5 elements\n");
        exit(1);
    }

    // Set loop bounds to stay within allocated memory
    mb = 1;  // because W starts at (mb-1)*18 offset
    ms = 1;  // step size in pointer increments
    me = mb + (data_size / 4); // ensure we don't exceed array bounds over iterations

    // Clamp me to safe value based on W's size and indexing: W + ((mb-1)*18) + (me-mb)*18 < W + 18
    // So (me - mb) < (18 - (mb-1)*18)/18 -> but simpler: since W has 18 elements,
    // and W starts at index (mb-1)*18, then final index is (me-1)*18 + 17 must be < 18
    // => (me-1)*18 + 17 < 18 => (me-1)*18 < 1 => me-1 == 0 => me <= 1
    // This suggests only one iteration is safe unless W is larger.

    // Therefore, we must scale W accordingly.
    // Original code uses W starting at offset (mb-1)*18, and increases by 18 per iteration.
    // To support multiple iterations, W must be large enough: size >= (me - mb + 1) * 18
    free(W);
    size_t required_W_size = (me - mb + 1) * 18;
    W = (R*)aligned_alloc(64, required_W_size * sizeof(R));

    // Re-initialize W values used in computation (indices 0-17 per block)
    for (INT iter = 0; iter < (me - mb + 1); ++iter) {
        R *Wblock = &W[iter * 18];
        for (int i = 0; i < 18; ++i) {
            Wblock[i] = sin((i + 1) * 0.1 * (iter + 1));
        }
    }

    // Initialize data arrays to prevent NaN/undefined behavior
    for (size_t i = 0; i < data_size; ++i) {
        Rp[i] = sin(i * 0.001);
        Ip[i] = cos(i * 0.001);
        Rm[i] = sin(i * 0.002);
        Im[i] = cos(i * 0.002);
    }

    // Ensure all pointer arithmetic stays within bounds during loop execution
    // The loop runs from m = mb to m < me, with W += 18 each time
    // Accesses: Rp[rs[k]], Ip[rs[k]], etc., where rs[k] <= 4 (max rs[4])
    // So as long as Rp, Ip, etc. have size >= max_index + 1, we're safe.
    // With rs[i]=i, max index is 4, so we need at least 5 elements per vector access.
    // But pointers are incremented by ms each loop: Rp += ms, etc.
    // Total advance: (me - mb) * ms
    // Final base address: Rp_initial + (me - mb)*ms
    // Max offset: base + 4
    // So we require: (me - mb)*ms + 4 < data_size
    if ((me - mb) * ms + 4 >= data_size) {
        me = mb + (data_size - 4) / ms;
    }

    // Final safeguard
    if (me <= mb) me = mb + 1;
}