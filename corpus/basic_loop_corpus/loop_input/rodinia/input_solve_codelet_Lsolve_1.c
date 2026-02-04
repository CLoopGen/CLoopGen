#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <string.h>

u_int dim;
u_int i;
double *b_ent;
double *out_ent;

void init_vars() {
    dim = 16777216; // 16M * sizeof(double) = ~128MB, sufficient for ~0.01 sec on modern CPU

    posix_memalign((void**)&b_ent, 32, dim * sizeof(double));
    posix_memalign((void**)&out_ent, 32, dim * sizeof(double));

    // Ensure the loop doesn't break immediately and runs through a significant portion
    // Initialize with non-zero after halfway point to ensure many iterations
    for (u_int j = 0; j < dim; j++) {
        if (j < dim / 2)
            b_ent[j] = 0.;
        else
            b_ent[j] = (j == dim / 2) ? 0. : 1.0;  // First non-zero at dim/2 + 1
    }

    // Initialize out_ent to zero or arbitrary values
    memset(out_ent, 0, dim * sizeof(double));
}