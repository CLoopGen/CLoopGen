#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_intp N;
extern npy_intp rstride;
extern npy_intp *iptr;
extern npy_intp i;
extern char *rptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (N <= 0) return;
    for (i = 0; i < N; i += 2) {
        npy_intp val1 = iptr[0];
        npy_intp val2 = iptr[1];
        *(npy_intp *)rptr = val1;
        *(npy_intp *)(rptr + rstride) = val2;
        rptr += 2 * rstride;
        iptr += 2;
    }
}
