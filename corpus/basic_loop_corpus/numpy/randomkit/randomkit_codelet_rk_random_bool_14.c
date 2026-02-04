#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char npy_bool;

typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_bool off;
extern npy_intp cnt;
extern npy_bool *out;
extern npy_intp i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < cnt; i++) {
    out[i] = off;
}

}
