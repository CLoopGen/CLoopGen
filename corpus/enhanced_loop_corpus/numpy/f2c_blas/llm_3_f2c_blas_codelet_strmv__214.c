#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef int logical;

extern integer *n;
extern real *a;
extern real *x;
extern integer a_dim1;
extern integer i__1;
extern integer i__;
extern integer j;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification - Indirect (Indexed) Access
    // Use an index array to access elements of 'x' and 'a' indirectly.
    // Simulate indirect addressing by creating a virtual index map for row indices.
    integer idx[(*n)+1]; // Index array for indirect access, 1-based indexing preserved
    for (integer k = 1; k <= *n; ++k) {
        idx[k] = k; // idx[i] maps logical index i to physical position i (can be randomized in real use cases)
    }
    for (j = *n; j >= 1; --j) {
        if (x[idx[j]] != 0.F) {
            temp = x[idx[j]];
            i__1 = j + 1;
            for (i__ = *n; i__ >= i__1; --i__) {
                // Indirect access to both x and a using mapped indices
                x[idx[i__]] += temp * a[idx[i__] + j * a_dim1];
            }
            if (nounit) {
                x[idx[j]] *= a[idx[j] + j * a_dim1];
            }
        }
    }
}
