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
    npy_intp j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 4; j++) {
            i1 += is1 / 4;
            i2 += is2 / 4;
            op += os / 4;
        }
    }
}
