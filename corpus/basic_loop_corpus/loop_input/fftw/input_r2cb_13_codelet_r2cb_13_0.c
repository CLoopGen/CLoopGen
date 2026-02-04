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

// Allocate sufficient data to make loop run ~0.01s (aim for ~64-128MB working set)
#define DATA_SIZE (1 << 20)  // 1M elements per array

static R *R0_data = NULL;
static R *R1_data = NULL;
static R *Cr_data = NULL;
static R *Ci_data = NULL;

R *R0;
R *R1;
R *Cr;
R *Ci;

stride rs;
stride csr;
stride csi;

INT v = 100000;  // Loop count to achieve desired runtime
INT ivs = 1;
INT ovs = 1;

E KP1_007074065 = 1.007074065;
E KP227708958 = 0.227708958;
E KP531932498 = 0.531932498;
E KP774781170 = 0.774781170;
E KP265966249 = 0.265966249;
E KP516520780 = 0.516520780;
E KP151805972 = 0.151805972;
E KP503537032 = 0.503537032;
E KP166666666 = 0.166666666;
E KP600925212 = 0.600925212;
E KP500000000 = 0.500000000;
E KP256247671 = 0.256247671;
E KP156891391 = 0.156891391;
E KP348277202 = 0.348277202;
E KP1_150281458 = 1.150281458;
E KP300238635 = 0.300238635;
E KP011599105 = 0.011599105;
E KP1_732050807 = 1.732050807;
E KP2_000000000 = 2.000000000;

INT i;

void init_vars(void)
{
    // Allocate large arrays to ensure measurable runtime
    R0_data = (R*)aligned_alloc(64, sizeof(R) * DATA_SIZE);
    R1_data = (R*)aligned_alloc(64, sizeof(R) * DATA_SIZE);
    Cr_data = (R*)aligned_alloc(64, sizeof(R) * DATA_SIZE);
    Ci_data = (R*)aligned_alloc(64, sizeof(R) * DATA_SIZE);

    if (!R0_data || !R1_data || !Cr_data || !Ci_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize data with non-zero values to avoid division by zero or flat data
    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        Cr_data[idx] = sin(idx * 0.001);
        Ci_data[idx] = cos(idx * 0.001);
        R0_data[idx] = 0.0;
        R1_data[idx] = 0.0;
    }

    // Set pointer aliases used in loop
    R0 = R0_data;
    R1 = R1_data;
    Cr = Cr_data;
    Ci = Ci_data;

    // Allocate and initialize stride arrays
    rs = (stride)malloc(7 * sizeof(INT));
    csr = (stride)malloc(7 * sizeof(INT));
    csi = (stride)malloc(7 * sizeof(INT));

    if (!rs || !csr || !csi) {
        fprintf(stderr, "Stride allocation failed\n");
        exit(1);
    }

    // Assign meaningful strides (unit strides for simplicity and correctness)
    for (int j = 0; j < 7; j++) {
        rs[j] = j;
        csr[j] = j;
        csi[j] = j;
    }

    // Adjust loop count `v` based on available data to prevent out-of-bounds access
    // The loop accesses indices up to 6 in some arrays via rs/csr/csi
    // Ensure that after v iterations, pointers don't go out of bounds
    // Each iteration advances R0, R1 by ovs, Cr, Ci by ivs
    // We need: initial + v * max_stride_offset < DATA_SIZE
    // Assume worst-case offset index is 6, so we require:
    //   base_ptr + 6 + v * step < DATA_SIZE
    // Choose v conservatively
    v = (DATA_SIZE - 10) / 6;
    if (v > 200000) v = 200000;
    if (v < 10000) v = 10000;
}