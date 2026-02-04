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
    // Variant 2: Indirect access via pointer arithmetic with forward traversal
    npy_intp *p_strides = strides + (nd - 1);
    npy_intp temp_size = 1;
    for (i = nd - 1; i >= 0; i--) {
        *p_strides = temp_size;
        if (dims[i]) {
            temp_size *= dims[i];
        } else {
            not_cf_contig = 0;
        }
        p_strides--;
    }
    itemsize = temp_size;
}
