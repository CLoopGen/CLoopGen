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
    npy_intp j;
    for (i = 0; i < cnt; i++) {
        out[i] = off + (uint16_t)(i % 16);
        for (j = 0; j < 3; j++) {
            out[i] ^= (out[i] >> j);
        }
    }
}
