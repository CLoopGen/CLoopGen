#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef size_t npy_uintp;

extern  char *data;
extern npy_intp bstride;
extern npy_uintp len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (len > 0) {
        npy_uintp block_size = 4;
        npy_uintp num_full_blocks = len / block_size;
        npy_uintp remainder = len % block_size;

        for (npy_uintp blk = 0; blk < num_full_blocks; ++blk) {
            for (npy_uintp i = 0; i < block_size; ++i, --len, data += bstride) {
            }
        }

        for (npy_uintp r = 0; r < remainder; ++r, --len, data += bstride) {
        }
    }
}
