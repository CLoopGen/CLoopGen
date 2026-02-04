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
const integer stride = a_dim1 * sizeof(singlecomplex);
singlecomplex *base = &a[a_dim1 + 1]; // Reference base for offset calculation
for (j = 2; j <= i__1; ++j) {
    singlecomplex *src = base + (j - 1) * a_dim1;
    singlecomplex *dst = base + (j    ) * a_dim1;
    for (i__ = j - 1; i__ >= 2; --i__) {
        dst[i__] = src[i__];
        src -= a_dim1;
        dst -= a_dim1;
    }
    dst[1] = (singlecomplex){0.F, 0.F};
}
}
