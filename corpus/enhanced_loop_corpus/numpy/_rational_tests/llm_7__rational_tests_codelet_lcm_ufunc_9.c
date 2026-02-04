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
    npy_intp local_k;
    char *local_i0 = i0;
    char *local_i1 = i1;
    char *local_o = o;
    for (local_k = 0; local_k < n; local_k++) {
        local_i0 += is0;
        local_i1 += is1;
        local_o += os;
    }
    i0 = local_i0;
    i1 = local_i1;
    o = local_o;
}
