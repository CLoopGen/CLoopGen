#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern integer *ihi;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Change memory access to indirect indexing via an index array to simulate irregular access patterns
    // Simulate indirect addressing using precomputed column-major offsets stored in a lookup table
    integer *index_map = (integer*)malloc(sizeof(integer) * (*n + 1));
    if (index_map == NULL) return; // Handle allocation failure

    // Precompute base indices for each column: map[j] = j * a_dim1
    for (integer col = 1; col <= *n; ++col) {
        index_map[col] = col * a_dim1;
    }

    for (j = *ihi; j >= i__1; --j) {
        i__2 = j - 1;
        for (i__ = 1; i__ <= i__2; ++i__) {
            a[i__ + index_map[j]] = 0.;  // Use precomputed offset
        }
        i__2 = *ihi;
        for (i__ = j + 1; i__ <= i__2; ++i__) {
            a[i__ + index_map[j]] = a[i__ + index_map[j - 1]];  // Indirect access via map
        }
        i__2 = *n;
        for (i__ = *ihi + 1; i__ <= i__2; ++i__) {
            a[i__ + index_map[j]] = 0.;
        }
    }

    free(index_map);
}
