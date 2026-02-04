#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_intp i;
extern npy_intp is1;
extern npy_intp is2;
extern npy_intp os;
extern npy_intp n;
extern char *i1;
extern char *i2;
extern char *op;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Assume is1, is2, and os represent strides; we change access to be consecutive by pre-computing base offsets
    npy_intp offset1 = 0;
    npy_intp offset2 = 0;
    npy_intp offset_out = 0;
    for (i = 0; i < n; i++) {
        // Access elements using computed byte offsets with unit stride simulation
        char *addr1 = i1 + offset1;
        char *addr2 = i2 + offset2;
        char *addr_out = op + offset_out;
        // Perform dummy operation to ensure usage
        *addr_out = *addr1 + *addr2;
        offset1 += is1;
        offset2 += is2;
        offset_out += os;
    }
}
