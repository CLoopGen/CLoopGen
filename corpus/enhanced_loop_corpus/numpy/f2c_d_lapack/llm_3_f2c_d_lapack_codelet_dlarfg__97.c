#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer i__1;
extern integer j;
extern doublereal beta;
extern doublereal safmin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern with a larger array and stride of 2
    const integer n = (i__1 + 1) * 2;
    doublereal *vec = (doublereal*)calloc(n, sizeof(doublereal));
    vec[0] = beta;
    for (j = 1; j <= i__1; ++j) {
        vec[2*j] = vec[2*(j-1)] * safmin;  // Stride of 2
    }
    beta = vec[2*i__1];
    free(vec);
}
