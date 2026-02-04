#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

extern integer *m;
extern singlecomplex *alpha;
extern singlecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    for (i__ = j + 1; i__ <= i__2; ++i__) {
        i__3 = i__ + j * a_dim1;
        a[i__3].r = alpha->r;
        a[i__3].i = alpha->i;
        if (i__ % 2 == 0) {
            i__3 = i__ - 1 + j * a_dim1;
            a[i__3].r *= 2.0f;
            a[i__3].i *= 2.0f;
        }
    }
}
}
