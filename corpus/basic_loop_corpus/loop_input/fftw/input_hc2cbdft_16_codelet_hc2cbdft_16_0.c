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
E KP923879532 = 0.9238795327550853;
E KP382683432 = 0.3826834323650898;
E KP707106781 = 0.7071067811865476;
INT m;

static size_t data_size;
static R *alloc_Rp;
static R *alloc_Ip;
static R *alloc_Rm;
static R *alloc_Im;
static R *alloc_W;
static INT *alloc_rs;

void init_vars() {
    // Estimate a problem size that will take ~0.01 seconds
    // Based on typical performance, aim for several million iterations.
    // The loop runs (me - mb) times. Set mb=0, me=2^20 ~ 1M iterations.
    mb = 0;
    me = 1 << 20;  // 1,048,576 iterations

    // Each iteration accesses up to rs[7], so rs must have at least 8 elements
    alloc_rs = calloc(8, sizeof(INT));
    if (!alloc_rs) exit(1);

    // Assign meaningful strides: use unit stride for simplicity
    for (INT i = 0; i < 8; i++) {
        alloc_rs[i] = i;  // rs[i] = i
    }
    rs = alloc_rs;

    // ms is the stride increment for pointer updates: set to 1 for unit step
    ms = 1;

    // Allocate arrays with sufficient size to cover all indexed accesses.
    // Maximum index used: 
    //   Rp[(rs[7])] -> Rp[7] when rs[7]=7
    //   Similarly for others. So we need at least size 8 per array.
    // But since we do (me - mb) iterations and update pointers by ms each time,
    // total memory should be large enough to allow all pointer advancements.

    // Total number of distinct positions accessed:
    // Rp starts at base, increases by ms each iteration -> accesses me - mb positions
    // But within each iteration, it uses indices via rs[] -> max offset rs[7]
    // So total size needed: (me - mb) + max(rs[0..7]) + 1
    INT max_offset = 0;
    for (INT i = 0; i < 8; i++) {
        if (alloc_rs[i] > max_offset) max_offset = alloc_rs[i];
    }

    size_t total_elements = (me - mb) + max_offset + 1;
    data_size = total_elements * sizeof(R);

    alloc_Rp = aligned_alloc(32, total_elements * sizeof(R));
    alloc_Ip = aligned_alloc(32, total_elements * sizeof(R));
    alloc_Rm = aligned_alloc(32, total_elements * sizeof(R));
    alloc_Im = aligned_alloc(32, total_elements * sizeof(R));
    alloc_W  = aligned_alloc(32, 30 * (me - mb) * sizeof(R));

    if (!alloc_Rp || !alloc_Ip || !alloc_Rm || !alloc_Im || !alloc_W) {
        exit(1);
    }

    // Initialize data with non-zero values to simulate real FFT data
    for (size_t i = 0; i < total_elements; i++) {
        alloc_Rp[i] = sin(i * 0.01);
        alloc_Ip[i] = cos(i * 0.01);
        alloc_Rm[i] = sin(i * 0.02);
        alloc_Im[i] = cos(i * 0.02);
    }

    // W has 30 entries per loop iteration
    for (INT i = 0; i < (me - mb); i++) {
        for (INT j = 0; j < 30; j++) {
            alloc_W[i * 30 + j] = sin((i + j) * 0.1);
        }
    }

    // Set initial pointer positions
    Rp = alloc_Rp;
    Ip = alloc_Ip;
    Rm = alloc_Rm + (max_offset * ms);  // Ensure Rm doesn't go negative early
    Im = alloc_Im + (max_offset * ms);

    // Adjust mb/me so that in the first iteration, W index ((mb-1)*30) is valid
    // We want: (mb - 1) >= 0 => mb >= 1
    // So shift mb and me accordingly
    mb = 1;
    me = mb + (1 << 18);  // Reduce slightly to keep runtime ~0.01s

    // Rebase W to start at correct offset
    W = alloc_W + ((mb - 1) * 30);
}