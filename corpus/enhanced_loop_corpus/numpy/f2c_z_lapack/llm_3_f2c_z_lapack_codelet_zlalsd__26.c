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
extern doublecomplex *b;
extern doublereal *rwork;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern doublecomplex z__1;
extern integer jcol;
extern integer jrow;
extern integer jimag;
extern integer jreal;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Use indirect addressing via index mapping: precomputed indices for scattered access
integer * restrict index_map = (integer*)malloc(((*n) * i__1) * sizeof(integer));
if (index_map == NULL) return; // Handle allocation failure

// Precompute row-major linear indices for indirect access
for (integer k = 0; k < *n * i__1; ++k) {
    integer jr = k % (*n) + 1;
    integer jc = k / (*n) + 1;
    index_map[k] = jr + jc * b_dim1;
}

for (jcol = 1; jcol <= i__1; ++jcol) {
    i__2 = *n;
    for (jrow = 1; jrow <= i__2; ++jrow) {
        // Compute linear index for indirect access
        integer linear_idx = (jrow - 1) + (jcol - 1) * (*n);
        i__3 = index_map[linear_idx]; // Indirect access through precomputed map
        integer rsrc = (jcol - 1) * (*n) * 2 + (jrow - 1) * 2 + 1; // Interleaved real/imag in rwork
        z__1.r = rwork[rsrc], z__1.i = rwork[rsrc + 1];
        b[i__3].r = z__1.r, b[i__3].i = z__1.i;
    }
}
free(index_map);
}
