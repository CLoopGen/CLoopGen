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
    for (i = 0; i < cnt; i++) {
        if (off != 0) {
            out[i] = off;
        } else {
            out[i] = 1;
        }
    }
}
