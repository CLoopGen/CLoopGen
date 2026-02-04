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
    npy_intp total_dims = 1;
    for (i = 0; i < nd; i++) {
        strides[i] = (total_dims * itemsize);
        total_dims *= (dims[i] > 0) ? dims[i] : 1;
        if (!dims[i]) {
            not_cf_contig = 0;
        }
    }
    itemsize = total_dims * itemsize;
}
