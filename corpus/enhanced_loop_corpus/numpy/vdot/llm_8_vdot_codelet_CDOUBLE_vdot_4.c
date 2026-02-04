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
    // Variant 1: Increased computational intensity with unrolled loop (factor of 2) and additional arithmetic operations
    npy_intp i_end = n - 1;
    for (i = 0; i < i_end; i += 2, ip1 += 2*is1, ip2 += 2*is2) {
        const double ip1r1 = ((double *)ip1)[0];
        const double ip1i1 = ((double *)ip1)[1];
        const double ip2r1 = ((double *)ip2)[0];
        const double ip2i1 = ((double *)ip2)[1];

        const double ip1r2 = ((double *)(ip1 + is1))[0];
        const double ip1i2 = ((double *)(ip1 + is1))[1];
        const double ip2r2 = ((double *)(ip2 + is2))[0];
        const double ip2i2 = ((double *)(ip2 + is2))[1];

        sumr += ip1r1 * ip2r1 + ip1i1 * ip2i1 + ip1r2 * ip2r2 + ip1i2 * ip2i2;
        sumi += ip1r1 * ip2i1 - ip1i1 * ip2r1 + ip1r2 * ip2i2 - ip1i2 * ip2r2;

        // Additional computation to increase arithmetic intensity
        sumr -= (ip1r1 - ip2r1) * (ip1i1 + ip2i1) * 0.01;
        sumi += (ip1i2 + ip2i2) * (ip1r2 - ip2r2) * 0.01;
    }
    // Handle remaining element if n is odd
    if (i < n) {
        const double ip1r = ((double *)ip1)[0];
        const double ip1i = ((double *)ip1)[1];
        const double ip2r = ((double *)ip2)[0];
        const double ip2i = ((double *)ip2)[1];
        sumr += ip1r * ip2r + ip1i * ip2i;
        sumi += ip1r * ip2i - ip1i * ip2r;
    }
}
