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
    for (i = 0; i < nd; i += 2) {
        if (i + 1 < nd) {
            strides[i] = itemsize;
            strides[i + 1] = itemsize;
            if (dims[i]) {
                itemsize *= dims[i];
            } else {
                not_cf_contig = 0;
            }
            if (dims[i + 1]) {
                itemsize *= dims[i + 1];
            } else {
                not_cf_contig = 0;
            }
        } else {
            strides[i] = itemsize;
            if (dims[i]) {
                itemsize *= dims[i];
            } else {
                not_cf_contig = 0;
            }
        }
    }
}
