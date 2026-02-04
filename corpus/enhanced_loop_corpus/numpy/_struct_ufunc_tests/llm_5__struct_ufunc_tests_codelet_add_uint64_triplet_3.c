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
    for (i = 0; i < n; i++) {
        if (is1 > 0 || is2 < 0) {
            i1 += is1;
            i2 += is2;
        }
        op += os;
    }
}
