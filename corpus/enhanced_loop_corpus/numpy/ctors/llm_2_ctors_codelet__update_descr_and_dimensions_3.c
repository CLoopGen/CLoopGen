#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int numnew;
extern npy_intp *mydim;
extern int i;
extern npy_intp tempsize;
extern npy_intp *mystrides;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward iteration and temporary array for strides
    npy_intp temp_strides[numnew];
    tempsize = 1;
    for (i = 0; i < numnew; i++) {
        temp_strides[i] = tempsize;
        tempsize *= (mydim[i] != 0) ? mydim[i] : 1;
    }
    // Copy results back in reverse order to maintain original semantics
    for (i = 0; i < numnew; i++) {
        mystrides[numnew - 1 - i] = temp_strides[i];
    }
}
