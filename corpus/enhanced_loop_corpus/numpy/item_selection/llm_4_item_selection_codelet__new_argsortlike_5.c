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
    for (i = 0; i < N; ++i) {
        if (*iptr != 0) {
            *(npy_intp *)rptr = *iptr;
        }
        iptr++;
        rptr += rstride;
    }
}
