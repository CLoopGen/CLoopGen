#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *v0;
extern double *v1;
extern double *v2;
extern double *v3;
extern double *w;
extern int i;
extern int len2;
extern double a0;
extern double a1;
extern double a2;
extern double a3;
extern double tmp0;
extern double tmp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling and restructured indexing
    // Instead of accessing 2*i and 2*i+1, we process two elements consecutively in a flattened manner.
    double *wi = w;
    const double *v0i = v0;
    const double *v1i = v1;
    const double *v2i = v2;
    const double *v3i = v3;

    for (i = 0; i < len2; i++) {
        tmp0 = wi[0] + a0 * v0i[0] + a1 * v1i[0] + a2 * v2i[0] + a3 * v3i[0];
        tmp1 = wi[1] + a0 * v0i[1] + a1 * v1i[1] + a2 * v2i[1] + a3 * v3i[1];

        wi[0] = tmp0;
        wi[1] = tmp1;

        wi += 2;
        v0i += 2;
        v1i += 2;
        v2i += 2;
        v3i += 2;
    }
}
