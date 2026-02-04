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
    char *local_data = data;
    npy_intp stride = bstride;
    npy_uintp count = len;
    for (; count > 0; --count) {
        *local_data = *local_data + 1;
        local_data += stride;
    }
    data = local_data;
}
