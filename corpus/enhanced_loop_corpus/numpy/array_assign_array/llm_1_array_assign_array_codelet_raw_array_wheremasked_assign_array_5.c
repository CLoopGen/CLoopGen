#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int ndim;
extern npy_intp shape_it[64];
extern npy_intp nitems;
extern npy_intp i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    nitems = 1;
    if (ndim > 0) {
        for (i = 0; i < ndim; i++) {
            nitems *= shape_it[i];
            npy_intp temp = i + 1;
            while (temp < ndim && temp == i + 1) { // Simulated inner logic without using while in spirit
                nitems *= shape_it[temp];
                temp++;
            }
            i = temp - 1;
        }
    }
}
