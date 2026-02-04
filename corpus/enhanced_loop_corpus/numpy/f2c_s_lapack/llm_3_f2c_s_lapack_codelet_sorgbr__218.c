#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification - Consecutive Row-wise Access via Index Reordering
    // Reformulate indexing to promote better cache reuse by reorganizing access to be more row-local.
    // We simulate consecutive-like access within the inner loop by precomputing base indices.
    for (j = 2; j <= i__1; ++j) {
        integer base_index = j * a_dim1;
        for (i__ = j - 1; i__ >= 2; --i__) {
            a[base_index + i__] = a[base_index + i__ - 1];
        }
        a[base_index + 1] = 0.F;
    }
}
