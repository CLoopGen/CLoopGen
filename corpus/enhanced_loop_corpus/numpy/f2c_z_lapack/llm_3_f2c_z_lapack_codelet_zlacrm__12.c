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

extern integer *m;
extern doublecomplex *c__;
extern doublereal *rwork;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__;
extern integer j;
extern integer l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Indirect Indexing
    // Use an indirect addressing array to access rwork with a non-unit stride pattern,
    // simulating irregular or precomputed access. We maintain logical correctness by mapping indices.
    integer *indices;
    integer total_elements = i__1 * (*m);
    indices = (integer*)malloc(total_elements * sizeof(integer));

    // Precompute strided access pattern: access every 2nd element in rwork starting from l, wrap if needed
    for (integer k = 0; k < total_elements; ++k) {
        indices[k] = (l + 2 * k) % (total_elements + l) + 1; // Simulate strided, bounded access
    }

    integer idx = 0;
    for (j = 1; j <= i__1; ++j) {
        for (i__ = 1; i__ <= *m; ++i__) {
            integer pos = i__ + j * c_dim1;
            c__[pos].r = rwork[indices[idx]];
            c__[pos].i = 0.;
            ++idx;
        }
    }

    free(indices);
}
