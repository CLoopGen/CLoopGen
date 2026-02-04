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

extern integer *n;
extern doublecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *n;
    // Access elements in column-major consecutive order using stride
    integer base_idx = (j - 1) * a_dim1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        integer idx = base_idx + i__;
        a[idx].r = 0.0;
        a[idx].i = 0.0;
    }
    // Set diagonal element using same indexing
    a[base_idx + j].r = 1.0;
    a[base_idx + j].i = 0.0;
}
}
