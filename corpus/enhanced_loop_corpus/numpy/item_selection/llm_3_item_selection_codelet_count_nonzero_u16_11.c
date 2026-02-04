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
    npy_intp i;
    char *temp_data = data + (len - 1) * bstride;
    for (i = 0; i < len; ++i, temp_data -= bstride) {
        // Reverse strided access: traverse from last element to first
        volatile char val = *temp_data; (void)val;
    }
}
