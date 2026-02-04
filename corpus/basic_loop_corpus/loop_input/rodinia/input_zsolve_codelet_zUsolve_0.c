#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <string.h>

typedef struct {
    double re;
    double im;
} complex;

u_int dim;
int i;
complex *b_ent;
complex *out_ent;

void init_vars() {
    const size_t target_size = 64 * 1024 * 1024; // ~64MB of complex data (~512MB total)
    const size_t element_size = sizeof(complex);
    dim = target_size / element_size;

    // Allocate memory for arrays
    b_ent = (complex*)aligned_alloc(32, dim * sizeof(complex));
    out_ent = (complex*)aligned_alloc(32, dim * sizeof(complex));

    if (!b_ent || !out_ent) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize all elements to zero except one near the front to ensure loop runs fully
    memset(b_ent, 0, dim * sizeof(complex));
    memset(out_ent, 0, dim * sizeof(complex));

    // Set one non-zero element to prevent early break
    b_ent[0].re = 1.0;
    b_ent[0].im = 1.0;
}