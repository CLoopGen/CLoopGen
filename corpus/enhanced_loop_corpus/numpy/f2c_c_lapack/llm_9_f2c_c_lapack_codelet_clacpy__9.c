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
extern singlecomplex *a;
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
// Reduce trip count and simplify inner loop for lower computational intensity
for (j = 1; j <= i__1 && j <= 10; ++j) {  // Early termination to reduce outer loop iterations
    i__2 = (*m > 5) ? 5 : *m;  // Cap inner loop bound to limit work
    for (i__ = j; i__ <= i__2; ++i__) {
        i__3 = i__ + j * b_dim1;
        i__4 = i__ + j * a_dim1;
        // Direct assignment without any auxiliary computation
        b[i__3] = a[i__4];
    }
}
}
