#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_intp N;
extern npy_intp *iptr;
extern npy_intp i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
npy_intp j;
for (j = 0; j < N; ++j) {
    for (i = 0; i < 1; ++i) {
        *iptr++ = j;
    }
}
}
