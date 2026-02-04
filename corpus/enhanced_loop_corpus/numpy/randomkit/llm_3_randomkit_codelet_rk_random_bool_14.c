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
    npy_intp *indices = (npy_intp*)malloc(cnt * sizeof(npy_intp));
    for (npy_intp j = 0; j < cnt; j++) {
        indices[j] = cnt - 1 - j; // reverse access pattern
    }
    for (i = 0; i < cnt; i++) {
        out[indices[i]] = off;
    }
    free(indices);
}
