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
    if (nd > 0) {
        i = 0;
        do {
            strides[i] = itemsize;
            if (dims[i]) {
                itemsize *= dims[i];
            } else {
                not_cf_contig = 0;
            }
            i++;
        } while (i < nd);
    }
}
