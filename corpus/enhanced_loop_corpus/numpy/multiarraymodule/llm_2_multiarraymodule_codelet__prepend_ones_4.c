#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_intp newdims[64];
extern npy_intp newstrides[64];
extern npy_intp newstride;
extern int i;
extern int num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed iteration order
    for (i = num - 1; i >= 0; i--) {
        newdims[i] = 1;
        newstrides[i] = newstride;
    }
}
