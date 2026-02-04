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
    npy_intp base_stride = itemsize;
    npy_bool local_not_cf = not_cf_contig;
    for (i = 0; i < nd; i++) {
        strides[i] = base_stride;
        if (dims[i]) {
            base_stride *= dims[i];
        } else {
            local_not_cf = 0;
        }
    }
    itemsize = base_stride;
    not_cf_contig = local_not_cf;
}
