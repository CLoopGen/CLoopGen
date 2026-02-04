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
    npy_intp *local_iptr = iptr;
    char *local_rptr = rptr;
    npy_intp local_stride = rstride;
    for (i = 0; i < N; ++i) {
        *(npy_intp *)(local_rptr + i * local_stride) = local_iptr[i];
    }
    iptr = local_iptr + N;
    rptr = local_rptr + N * local_stride;
}
