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
extern npy_intp count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_uintp step = 4;
    npy_uintp remainder = len % step;
    npy_uintp full_iterations = len - remainder;

    for (npy_uintp i = 0; i < full_iterations; i += step, data += bstride * step) {
        count += (*(data) != 0);
        count += (*(data + bstride) != 0);
        count += (*(data + 2*bstride) != 0);
        count += (*(data + 3*bstride) != 0);
    }

    for (npy_uintp i = 0; i < remainder; ++i, --len, data += bstride) {
        count += (*data != 0);
    }
}
