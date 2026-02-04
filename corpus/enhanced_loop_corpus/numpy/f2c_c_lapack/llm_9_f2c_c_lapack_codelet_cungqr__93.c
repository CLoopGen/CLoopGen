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
extern integer i__3;
extern integer i__;
extern integer j;
extern integer kk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (kk < i__1) {
    for (j = kk + 1; j <= i__1; j += 2) {
        i__2 = kk >> 1;
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__3 = i__ + j * a_dim1;
            a[i__3].r = 0.F; a[i__3].i = 0.F;
            if (j + 1 <= i__1) {
                i__3 = i__ + (j + 1) * a_dim1;
                a[i__3].r = 0.F; a[i__3].i = 0.F;
            }
        }
    }
}
}
