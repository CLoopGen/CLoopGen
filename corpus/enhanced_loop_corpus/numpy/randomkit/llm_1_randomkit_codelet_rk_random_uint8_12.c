#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char npy_uint8;

typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_uint8 off;
extern npy_intp cnt;
extern npy_uint8 *out;
extern npy_intp i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp block_size = 16;
    npy_intp num_blocks = (cnt + block_size - 1) / block_size;
    npy_intp b, k;

    for (b = 0; b < num_blocks; b++) {
        for (k = 0; k < block_size; k++) {
            npy_intp idx = b * block_size + k;
            if (idx < cnt) {
                out[idx] = off;
            }
        }
    }
}
