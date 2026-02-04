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
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *m; j >= 2; --j) {
    a[j * a_dim1 + 1] = 0.;
    i__1 = *m;
    for (i__ = j + 1; i__ <= i__1; ++i__) {
        ptrdiff_t idx_current = i__ + j * a_dim1;
        ptrdiff_t idx_prev = i__ + (j - 1) * a_dim1;
        a[idx_current] = a[idx_prev];
    }
}
}
