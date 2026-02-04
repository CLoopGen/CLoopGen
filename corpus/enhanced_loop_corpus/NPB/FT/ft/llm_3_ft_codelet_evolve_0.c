#include <stdio.h>

typedef struct {
    double real;
    double imag;
} dcomplex;

extern  double ex[221185];
extern dcomplex u0[128][256][256];
extern dcomplex u1[128][256][256];
extern int t;
extern int indexmap[128][256][256];
extern int d[3];
extern int i;
extern int j;
extern int k;



void loop(){
    // Variant 2: Use indirect array indexing via flattened index and pointer arithmetic
    // This variant linearizes the 3D indices into a 1D access pattern using an auxiliary index array
    int total_elements = d[0] * d[1] * d[2];
    static int flat_index_cache[128*256*256]; // Precomputed flat indices (within bounds)
    int idx_gen = 0;
    // Precompute indirect access indices (simulating irregular access pattern)
    for (k = 0; k < d[2]; k++) {
        for (j = 0; j < d[1]; j++) {
            for (i = 0; i < d[0]; i++) {
                flat_index_cache[idx_gen++] = k * d[1] * d[0] + j * d[0] + i;
            }
        }
    }

    dcomplex *u0_ptr = &u0[0][0][0];
    dcomplex *u1_ptr = &u1[0][0][0];
    int (*indexmap_ptr)[256][256] = indexmap;

    for (int n = 0; n < total_elements; n++) {
        int flat_idx = flat_index_cache[n];
        int idx_ex = t * indexmap_ptr[flat_idx / (256*256)][(flat_idx / 256) % 256][flat_idx % 256];
        u1_ptr[flat_idx].real = u0_ptr[flat_idx].real * ex[idx_ex];
        u1_ptr[flat_idx].imag = u0_ptr[flat_idx].imag * ex[idx_ex];
    }
}
