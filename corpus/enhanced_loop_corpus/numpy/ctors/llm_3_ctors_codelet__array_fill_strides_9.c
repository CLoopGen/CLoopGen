#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef unsigned char npy_bool;

extern npy_intp *strides;
extern  npy_intp *dims;
extern int nd;
extern size_t itemsize;
extern int i;
extern npy_bool not_cf_contig;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp temp_strides[16]; // Assuming maximum dimensions is 16
    npy_intp temp_itemsize = itemsize;
    for (i = 0; i < nd; i++) {
        temp_strides[i] = temp_itemsize;
        if (dims[i]) {
            temp_itemsize *= dims[i];
        } else {
            not_cf_contig = 0;
        }
    }
    // Perform strided write back to original strides array
    for (i = 0; i < nd; i += 2) {
        strides[i] = temp_strides[i];
        if (i + 1 < nd) {
            strides[i + 1] = temp_strides[i + 1];
        }
    }
}
