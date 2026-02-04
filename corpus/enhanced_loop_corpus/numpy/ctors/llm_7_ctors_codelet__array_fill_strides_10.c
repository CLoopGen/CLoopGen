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
    npy_bool local_not_cf_contig = not_cf_contig;
    npy_intp running_size = itemsize;
    for (i = nd - 1; i >= 0; i--) {
        strides[i] = running_size;
        running_size = (dims[i] > 0) ? running_size * dims[i] : running_size;
        if (!dims[i]) {
            local_not_cf_contig = 0;
        }
    }
    itemsize = running_size;
    not_cf_contig = local_not_cf_contig;
}
