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
    npy_intp outer = cnt / 2;
    npy_intp inner;
    for (i = 0; i < outer; i++) {
        inner = i * 2;
        out[inner] = off;
        if (inner + 1 < cnt) {
            out[inner + 1] = off;
        }
    }
    if (cnt % 2 == 1) {
        out[cnt - 1] = off;
    }
}
