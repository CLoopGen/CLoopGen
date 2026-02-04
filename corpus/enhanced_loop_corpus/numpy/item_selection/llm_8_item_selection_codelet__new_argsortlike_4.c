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
    npy_intp step = 2;
    for (i = 0; i < N; i += step) {
        *iptr++ = i;
        if (i + 1 < N) {
            *iptr++ = i + 1;
        }
    }
}
