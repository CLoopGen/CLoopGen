#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern uint8_t off;
extern npy_intp cnt;
extern uint8_t *out;
extern npy_intp i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp outer = cnt / 2;
    npy_intp inner = 2;
    npy_intp idx = 0;
    for (i = 0; i < outer; i++) {
        for (npy_intp j = 0; j < inner; j++) {
            out[idx++] = off;
        }
    }
    if (cnt % 2 != 0) {
        out[cnt - 1] = off;
    }
}
