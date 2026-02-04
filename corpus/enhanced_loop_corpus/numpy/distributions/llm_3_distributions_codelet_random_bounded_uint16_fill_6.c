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
    // Variant 2: Strided memory access with stride of 4
    npy_intp i;
    const npy_intp stride = 4;
    // Process elements in a strided manner
    for (i = 0; i < cnt; i++) {
        npy_intp idx = (i * stride) % cnt; // Ensure index is within bounds
        out[idx] = off;
    }
}
