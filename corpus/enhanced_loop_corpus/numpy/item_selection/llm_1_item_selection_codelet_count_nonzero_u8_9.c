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
    npy_uintp outer = len / 10;
    npy_uintp remainder = len % 10;
    for (; outer > 0; --outer) {
        npy_uintp inner;
        for (inner = 0; inner < 10; ++inner, data += bstride) {
            count += (*data != 0);
        }
    }
    for (; remainder > 0; --remainder, data += bstride) {
        count += (*data != 0);
    }
}
