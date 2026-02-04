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
    npy_intp outer;
    for (outer = 0; outer < N; ++outer) {
        i = outer;
        *(npy_intp *)rptr = *iptr++;
        rptr += rstride;
    }
}
