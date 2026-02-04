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
        for (j = 0; j < 1; j++) {
            out[i] = off;
        }
    }
}
