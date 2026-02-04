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
extern doublecomplex *b;
extern doublereal *rwork;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    i__3 = j * b_dim1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        integer idx_b = i__ + i__3;
        integer idx_rw = (j - 1) * *m + i__;
        rwork[idx_rw] = b[idx_b].r;
        if (i__ % 2 == 0) {
            rwork[idx_rw] += b[idx_b - b_dim1].r;
        }
    }
}
}
