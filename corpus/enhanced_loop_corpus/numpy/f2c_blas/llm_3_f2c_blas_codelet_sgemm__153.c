#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern integer *k;
extern real *alpha;
extern real *a;
extern real *b;
extern real *beta;
extern real *c__;
extern integer a_dim1;
extern integer b_dim1;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer l;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change to indirect memory access using an index map (simulated via precomputed indices)
integer * restrict idx_map = (integer*)malloc((*k) * sizeof(integer));
if (!idx_map) return; // Handle allocation failure
for (integer init = 0; init < *k; ++init) {
    idx_map[init] = init + 1; // Identity map for realism, but enables indirect access pattern
}

for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        temp = 0.F;
        i__3 = *k;
        for (l = 0; l < i__3; ++l) {
            integer actual_l = idx_map[l]; // Indirect access through index map
            temp += a[actual_l + i__ * a_dim1] * b[actual_l + j * b_dim1];
        }
        if (*beta == 0.F) {
            c__[i__ + j * c_dim1] = *alpha * temp;
        } else {
            c__[i__ + j * c_dim1] = *alpha * temp + *beta * c__[i__ + j * c_dim1];
        }
    }
}
free(idx_map);
}
