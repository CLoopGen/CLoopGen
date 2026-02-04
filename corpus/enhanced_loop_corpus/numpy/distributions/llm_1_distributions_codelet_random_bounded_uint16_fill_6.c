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
    npy_intp outer = cnt / 2;
    npy_intp remainder = cnt % 2;
    npy_intp idx = 0;
    for (i = 0; i < outer; i++) {
        out[idx] = off;
        out[idx + 1] = off;
        idx += 2;
    }
    if (remainder) {
        out[idx] = off;
    }
}
