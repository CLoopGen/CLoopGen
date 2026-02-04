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
    uint64_t temp = off;
    for (i = 0; i < cnt; i++) {
        out[i] = temp;
        temp = out[i]; // Introduce RAW and WAW dependency: read after write, write after write on 'temp'
    }
}
