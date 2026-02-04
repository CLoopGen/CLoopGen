#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef double npy_longdouble;

extern char *ip1;
extern npy_intp is1;
extern char *ip2;
extern npy_intp is2;
extern npy_intp n;
extern npy_longdouble tmpr;
extern npy_longdouble tmpi;
extern npy_intp i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array indexing (assuming data is packed consecutively in memory)
    npy_longdouble * restrict p1 = (npy_longdouble *)ip1;
    npy_longdouble * restrict p2 = (npy_longdouble *)ip2;
    for (i = 0; i < n; i++) {
        const npy_longdouble ip1r = p1[2*i + 0];
        const npy_longdouble ip1i = p1[2*i + 1];
        const npy_longdouble ip2r = p2[2*i + 0];
        const npy_longdouble ip2i = p2[2*i + 1];
        tmpr += ip1r * ip2r + ip1i * ip2i;
        tmpi += ip1r * ip2i - ip1i * ip2r;
    }
}
