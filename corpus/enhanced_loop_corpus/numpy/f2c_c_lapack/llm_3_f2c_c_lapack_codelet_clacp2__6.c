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
extern real *a;
extern singlecomplex *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    for (i__ = j; i__ <= i__2; ++i__) {
        i__3 = j + i__ * b_dim1;  // Transposed access pattern: swap i and j indices in b
        i__4 = i__ + j * a_dim1;
        b[i__3].r = a[i__4];
        b[i__3].i = 0.F;
    }
}
}
