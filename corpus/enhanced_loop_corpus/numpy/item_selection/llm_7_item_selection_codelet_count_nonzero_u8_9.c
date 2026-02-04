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
    npy_intp local_count = 0;
    char *local_data = data;
    npy_intp local_stride = bstride;
    npy_uintp local_len = len;

    for (; local_len > 0; --local_len, local_data += local_stride) {
        local_count += (*local_data != 0);
    }
    count += local_count;
}
