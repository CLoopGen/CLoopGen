#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern uint16_t off;
extern npy_intp cnt;
extern uint16_t *out;
extern npy_intp i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling by 2
    npy_intp i;
    for (i = 0; i < cnt - 1; i += 2) {
        out[i] = off;
        out[i + 1] = off;
    }
    // Handle remaining element if cnt is odd
    if (i < cnt) {
        out[i] = off;
    }
}
