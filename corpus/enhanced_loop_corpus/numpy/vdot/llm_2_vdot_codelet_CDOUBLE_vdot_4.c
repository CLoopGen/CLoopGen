#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern char *ip1;
extern npy_intp is1;
extern char *ip2;
extern npy_intp is2;
extern npy_intp n;
extern double sumr;
extern double sumi;
extern npy_intp i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (assume data is tightly packed, use array indexing)
    double *ap1 = (double*)ip1;
    double *ap2 = (double*)ip2;
    for (i = 0; i < n; i++) {
        const npy_intp idx1 = i * (is1 / sizeof(double));
        const npy_intp idx2 = i * (is2 / sizeof(double));
        const double ip1r = ap1[idx1];
        const double ip1i = ap1[idx1 + 1];
        const double ip2r = ap2[idx2];
        const double ip2i = ap2[idx2 + 1];
        sumr += ip1r * ip2r + ip1i * ip2i;
        sumi += ip1r * ip2i - ip1i * ip2r;
    }
}
