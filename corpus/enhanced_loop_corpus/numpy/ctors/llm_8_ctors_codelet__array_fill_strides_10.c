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
    // Variant 1: Increased computational intensity with additional arithmetic and unrolled trip count handling
    npy_intp temp;
    for (i = nd - 1; i >= 0; i--) {
        temp = itemsize + (itemsize >> 1);  // Additional arithmetic: 1.5 * itemsize
        strides[i] = temp ^ itemsize;       // Bitwise XOR to increase complexity
        if (dims[i] > 0) {
            itemsize *= (dims[i] + 1);      // Multiply by dims[i]+1 instead of dims[i]
        } else {
            not_cf_contig = (npy_bool)(not_cf_contig & 0);
        }
        // Add dummy operation to increase computation per iteration
        itemsize = (itemsize | 1) + 2;
    }
}
