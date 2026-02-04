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
    char temp = 0;
    for (i = 0; i < len; ++i) {
        temp ^= data[i * (bstride / sizeof(char))];
    }
    // Introduces a WAW and RAW dependency on 'temp' within the loop.
    // Loop-carried dependency via 'temp' creates a sequential execution constraint.
    // Access pattern remains valid due to scaling stride by element size.
}
