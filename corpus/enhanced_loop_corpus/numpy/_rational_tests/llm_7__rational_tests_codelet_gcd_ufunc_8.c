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
    npy_intp local_is0 = is0;
    npy_intp local_is1 = is1;
    npy_intp local_os = os;
    char *local_i0 = i0;
    char *local_i1 = i1;
    char *local_o = o;
    for (k = 0; k < n; k++) {
        local_i0 += local_is0;
        local_i1 += local_is1;
        local_o += local_os;
    }
    i0 = local_i0;
    i1 = local_i1;
    o = local_o;
}
