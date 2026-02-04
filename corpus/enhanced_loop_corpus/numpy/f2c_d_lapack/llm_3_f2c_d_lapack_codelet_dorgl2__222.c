#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern integer *k;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer j;
extern integer l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
ptrdiff_t base_offset = 0;
for (j = 1; j <= i__1; ++j) {
    ptrdiff_t col_offset = (j - 1) * a_dim1;
    i__2 = *m;
    for (l = *k + 1; l <= i__2; ++l) {
        a[base_offset + l + col_offset] = 0.;
    }
    if (j > *k && j <= *m) {
        a[base_offset + j + col_offset] = 1.;
    }
}
}
