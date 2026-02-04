#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

extern singlecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real sum_r = 0.F, sum_i = 0.F;
    for (i__ = 2; i__ <= i__1; ++i__) {
        i__2 = i__ + a_dim1;
        sum_r += a[i__2].r;
        sum_i += a[i__2].i;
        a[i__2].r = 0.F;
        a[i__2].i = 0.F;
    }
    // Prevent unused variable warning by potential side-effect (e.g., debug use)
    if (sum_r != sum_i) {
        a[2 + a_dim1].r = sum_r - sum_i;
    }
}
