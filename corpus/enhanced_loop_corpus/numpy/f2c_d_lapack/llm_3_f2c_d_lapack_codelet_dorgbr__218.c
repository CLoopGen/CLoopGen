#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 2; j <= i__1; ++j) {
    ptrdiff_t base_idx = j * a_dim1;
    for (i__ = j - 1; i__ >= 2; --i__) {
        ptrdiff_t current = base_idx + i__;
        ptrdiff_t prev = base_idx + i__ - 1;
        a[current] = a[prev];
    }
    a[base_idx + 1] = 0.;
}
}
