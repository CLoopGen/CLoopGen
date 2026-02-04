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
    npy_intp j, k;
    npy_intp block_size = 16;
    npy_intp full_blocks = N / block_size;
    npy_intp remainder = N % block_size;

    for (j = 0; j < full_blocks; ++j) {
        for (k = 0; k < block_size; ++k) {
            i = j * block_size + k;
            *(npy_intp *)rptr = *iptr++;
            rptr += rstride;
        }
    }

    for (i = full_blocks * block_size; i < N; ++i) {
        *(npy_intp *)rptr = *iptr++;
        rptr += rstride;
    }
}
