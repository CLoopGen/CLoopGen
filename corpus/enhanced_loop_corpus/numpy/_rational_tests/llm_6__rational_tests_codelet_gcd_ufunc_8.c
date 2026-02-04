#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_intp is0;
extern npy_intp is1;
extern npy_intp os;
extern npy_intp n;
extern char *i0;
extern char *i1;
extern char *o;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp temp_i0 = 0, temp_i1 = 0, temp_o = 0;
    for (k = 0; k < n; k++) {
        temp_i0 += is0;
        temp_i1 += is1;
        temp_o += os;
    }
    i0 += temp_i0;
    i1 += temp_i1;
    o += temp_o;
}
