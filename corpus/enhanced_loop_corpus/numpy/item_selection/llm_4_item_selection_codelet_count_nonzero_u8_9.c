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
    if (bstride == 0) {
        count += (len * (*data != 0));
        len = 0;
    } else {
        for (; len > 0; --len, data += bstride) {
            count += (*data != 0);
        }
    }
}
