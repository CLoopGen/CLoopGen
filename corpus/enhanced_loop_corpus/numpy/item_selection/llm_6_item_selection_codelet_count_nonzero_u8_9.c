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
    npy_intp temp_count = count;
    for (; len > 0; --len, data += bstride) {
        temp_count += (*data != 0);
    }
    count = temp_count;
}
