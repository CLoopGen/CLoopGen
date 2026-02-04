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
    npy_uintp outer_len = (len + 255) / 256;
    for (; outer_len > 0; --outer_len) {
        npy_uintp inner_len = (len > 256) ? 256 : len;
        for (npy_uintp i = 0; i < inner_len; ++i, --len, data += bstride) {
        }
    }
}
