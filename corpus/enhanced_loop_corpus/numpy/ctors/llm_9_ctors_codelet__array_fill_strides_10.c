#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef unsigned char npy_bool;

extern npy_intp *strides;
extern  npy_intp *dims;
extern int nd;
extern size_t itemsize;
extern int i;
extern npy_bool not_cf_contig;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count via stride skipping and simplified operations
    // Simulate processing only even indices by adjusting loop step logically
    for (i = (nd - 1) & (~1); i >= 0; i -= 2) {  // Process every other index starting from highest even
        strides[i] = itemsize;
        if (i < nd && dims[i]) {
            itemsize <<= 1;  // Use bit shift instead of multiplication for reduced cost
        } else {
            not_cf_contig = 1;  // Simplified assignment
        }
        // Handle next index within same iteration if exists (simulated unroll of 2)
        if (i > 0) {
            strides[i-1] = itemsize;
            if (dims[i-1]) {
                itemsize <<= 1;
            }
        }
    }
    // Final cleanup for odd-length case
    if (nd > 0 && (nd % 2) == 1) {
        strides[0] = itemsize;
        if (!dims[0]) {
            not_cf_contig = 0;
        }
    }
}
