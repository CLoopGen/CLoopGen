#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *a;
extern real *work;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern real r__1;
extern integer i__;
extern integer j;
extern real sum;
extern real absa;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Modify memory access pattern to use indirect indexing via an index array
// Simulate indirect access using a precomputed index map (emulated here with offset array)
integer *index_map = (integer*)malloc(i__1 * sizeof(integer));
for (integer idx = 0; idx < i__1; ++idx) {
    index_map[idx] = idx + 1; // Identity mapping for realism, but enables indirect access
}

for (j = 1; j <= i__1; ++j) {
    sum = 0.F;
    i__2 = j - 1;
    for (i__ = 0; i__ < i__2; ++i__) { // Use index_map[i__] as indirect index
        integer actual_i = index_map[i__];
        absa = (r__1 = a[actual_i + j * a_dim1], (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
        sum += absa;
        work[actual_i] += absa;
    }
    work[j] = sum + (r__1 = a[j + j * a_dim1], (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
}
free(index_map);
}
