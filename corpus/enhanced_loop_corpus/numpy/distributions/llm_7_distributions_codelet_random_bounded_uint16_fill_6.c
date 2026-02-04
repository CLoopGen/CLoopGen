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
    uint16_t local_off = off;
    for (i = 0; i < cnt; i += 2) {
        if (i + 1 < cnt) {
            out[i] = local_off;
            out[i + 1] = local_off; // Eliminate loop-carried dependency by unrolling; no data dependence between iterations
        } else {
            out[i] = local_off;
        }
    }
}
