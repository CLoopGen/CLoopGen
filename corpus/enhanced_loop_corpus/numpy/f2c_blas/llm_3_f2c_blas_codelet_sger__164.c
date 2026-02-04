#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern real *alpha;
extern real *x;
extern real *y;
extern integer *incy;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer jy;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Access with Indirect Indexing via Lookup Table
    // Replace direct jy update with an index map that defines non-unit stride access pattern.
    // Precomputed index_map holds the actual indices into array y based on initial jy and incy.
    integer *index_map = (integer*)malloc(i__1 * sizeof(integer));
    integer current_y_index = jy;
    for (integer idx = 0; idx < i__1; ++idx) {
        index_map[idx] = current_y_index;
        current_y_index += *incy;
    }

    for (j = 1; j <= i__1; ++j) {
        if (y[index_map[j - 1]] != 0.F) {
            temp = *alpha * y[index_map[j - 1]];
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                // Maintain original column-major access in matrix 'a'
                a[i__ + j * a_dim1] += x[i__] * temp;
            }
        }
    }

    free(index_map);
}
