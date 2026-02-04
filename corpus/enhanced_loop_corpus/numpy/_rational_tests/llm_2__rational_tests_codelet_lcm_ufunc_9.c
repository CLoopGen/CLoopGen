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
    // Variant 1: Consecutive memory access pattern
    // Assume that the strides (is0, is1, os) are folded into precomputed base pointers
    // We rewrite the loop to access consecutive elements by pre-biasing pointers
    char *base_i0 = i0 + is0 * n;
    char *base_i1 = i1 + is1 * n;
    char *base_o  = o  + os  * n;

    for (k = 0; k < n; k++) {
        i0 = base_i0 - is0 * (n - k);
        i1 = base_i1 - is1 * (n - k);
        o  = base_o  - os  * (n - k);
    }
}
