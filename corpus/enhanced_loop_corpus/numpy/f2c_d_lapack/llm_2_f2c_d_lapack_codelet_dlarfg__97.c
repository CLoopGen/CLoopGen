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
    // Variant 1: Consecutive memory access pattern using an array to simulate scaling by safmin
    doublereal *beta_arr = (doublereal*)calloc(i__1 + 1, sizeof(doublereal));
    beta_arr[0] = beta;
    for (j = 1; j <= i__1; ++j) {
        beta_arr[j] = beta_arr[j-1] * safmin;
    }
    beta = beta_arr[i__1];
    free(beta_arr);
}
