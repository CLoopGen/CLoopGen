#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern uint32_t off;
extern npy_intp cnt;
extern uint32_t *out;
extern npy_intp i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < cnt; i++) {
    out[i] = off;
}

}
