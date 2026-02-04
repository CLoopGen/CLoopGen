#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_intp is0;
extern npy_intp is1;
extern npy_intp os;
extern npy_intp n;
extern char *i0;
extern char *i1;
extern char *o;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with fixed offset jumping every 2 iterations
    // Simulate a strided traversal by unrolling the loop with step size 2
    // This changes access pattern to process elements in larger jumps when possible

    npy_intp stride_factor = 2;
    npy_intp remainder = n % stride_factor;
    npy_intp full_iters = n - remainder;

    for (k = 0; k < full_iters; k += stride_factor) {
        // Update pointers twice per iteration to simulate larger stride effect
        i0 += is0 * stride_factor;
        i1 += is1 * stride_factor;
        o  += os  * stride_factor;
    }

    // Handle remaining iterations linearly
    for (; k < n; k++) {
        i0 += is0;
        i1 += is1;
        o  += os;
    }
}
