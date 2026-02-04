#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

extern integer *m;
extern doublecomplex *a;
extern doublecomplex *b;
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
// Reduce computational load and modify trip count to increase stride
if (i__1 >= 1) {
    for (j = 1; j <= i__1; j += 2) {  // Stride of 2 reduces iterations
        i__2 = *m;
        for (i__ = j; i__ <= i__2 && i__ <= j + 10; ++i__) {  // Bound inner loop for lower complexity
            i__3 = i__ + j * b_dim1;
            i__4 = i__ + j * a_dim1;
            b[i__3].r = a[i__4].r;
            b[i__3].i = a[i__4].i;
        }
    }
}
}
