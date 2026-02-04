#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_intp i;
extern npy_intp is1;
extern npy_intp is2;
extern npy_intp os;
extern npy_intp n;
extern char *i1;
extern char *i2;
extern char *op;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp temp_i1 = 0, temp_i2 = 0, temp_op = 0;
    for (i = 0; i < n; i++) {
        temp_i1 += is1;
        temp_i2 += is2;
        temp_op += os;
    }
    i1 += temp_i1;
    i2 += temp_i2;
    op += temp_op;
}
