#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer kk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Decreased loop nesting depth by flattening the two loops into one using linear indexing
    // Assuming row-major access and valid index range
    integer idx;
    integer total_elements = (*m - kk) * i__1; // Approximate total iterations
    for (idx = 0; idx < total_elements; ++idx) {
        i__ = (idx % (*m - kk)) + kk + 1;
        j = (idx / (*m - kk)) + 1;
        if (j <= i__1 && i__ <= *m) {
            a[i__ + j * a_dim1] = 0.;
        }
    }
}
