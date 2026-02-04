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
    npy_intp k1;
    for (k1 = 0; k1 < n; k1++) {
        for (k = 0; k < 1; k++) {
            i0 += is0;
            i1 += is1;
            o += os;
        }
    }
}
