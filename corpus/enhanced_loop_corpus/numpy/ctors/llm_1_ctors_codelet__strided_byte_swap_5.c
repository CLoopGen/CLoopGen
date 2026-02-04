#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern void *p;
extern npy_intp stride;
extern npy_intp n;
extern char *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp outer, inner;
    npy_intp block_size = 4;
    npy_intp num_blocks = (n + block_size - 1) / block_size;
    for (outer = 0; outer < num_blocks; outer++) {
        for (inner = 0; inner < block_size; inner++) {
            npy_intp idx = outer * block_size + inner;
            if (idx >= n) break;
            a = (char *)p + idx * stride;
        }
    }
}
