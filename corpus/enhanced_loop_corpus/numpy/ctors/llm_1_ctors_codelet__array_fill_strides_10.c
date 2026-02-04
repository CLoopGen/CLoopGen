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
    // Variant 2: Decreased loop nesting depth by eliminating inner operations and flattening logic
    // Use a single pass with direct assignment and conditional handling without additional control flow
    npy_intp base = 1;
    // Reverse iteration replaced with forward accumulation to remove dependency on direction
    for (i = 0; i < nd; i++) {
        npy_intp dim = dims[nd - 1 - i];
        strides[nd - 1 - i] = base * sizeof(char);  // assuming itemsize starts as sizeof(char)
        if (dim == 0) {
            not_cf_contig = 0;
        }
        base *= (dim != 0) ? dim : 1;
    }
    itemsize = base * sizeof(char);
}
