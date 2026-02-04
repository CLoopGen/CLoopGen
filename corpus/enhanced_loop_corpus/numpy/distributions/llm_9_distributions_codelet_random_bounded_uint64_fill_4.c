#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern uint64_t off;
extern npy_intp cnt;
extern uint64_t *out;
extern npy_intp i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced effective trip count by loop unrolling with stride of 2
    // This reduces loop overhead and increases memory access stride
    npy_intp limit = cnt - 1;
    for (i = 0; i < limit; i += 2) {
        out[i] = off;
        out[i + 1] = off + 1;
    }
    // Handle remaining element if cnt is odd
    if (i < cnt) {
        out[i] = off;
    }
}
