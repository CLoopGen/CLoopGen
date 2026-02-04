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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 2; j <= i__1; ++j) {
    for (i__ = j - 1; i__ >= 2; --i__) {
        i__2 = (i__ * a_dim1) + j;
        i__3 = ((i__ - 1) * a_dim1) + j;
        a[i__2].r = a[i__3].r;
        a[i__2].i = a[i__3].i;
    }
    i__2 = (1 * a_dim1) + j;
    a[i__2].r = 0.F;
    a[i__2].i = 0.F;
}
}
