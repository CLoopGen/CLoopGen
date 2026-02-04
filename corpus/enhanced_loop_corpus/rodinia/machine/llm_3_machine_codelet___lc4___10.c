#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *v0;
extern double *v1;
extern double *v2;
extern double *v3;
extern double *w;
extern int len;
extern int i;
extern double a0;
extern double a1;
extern double a2;
extern double a3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access (backward traversal)
    for (i = len - 1; i >= 0; i--) {
        w[i] += a0 * v0[i] + a1 * v1[i] + a2 * v2[i] + a3 * v3[i];
    }
}
