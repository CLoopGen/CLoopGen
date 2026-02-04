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
    // Variant 2: Reduced computational intensity with halved effective trip count and simplified operations
    npy_intp stride = 2;
    npy_intp i_end = n - (n % stride);
    for (i = 0; i < i_end; i += stride, ip1 += stride*is1, ip2 += stride*is2) {
        const double ip1r = ((double *)ip1)[0];
        const double ip2r = ((double *)ip2)[0];
        // Only real part interaction computed; ignore imaginary contribution for reduced complexity
        sumr += ip1r * ip2r;
        // Reduce update frequency of sumi by only using one component
        sumi += ip1r * 0.5;
    }
    // Remainder loop for leftover elements
    for (; i < n; i++, ip1 += is1, ip2 += is2) {
        const double ip1r = ((double *)ip1)[0];
        const double ip1i = ((double *)ip1)[1];
        const double ip2r = ((double *)ip2)[0];
        const double ip2i = ((double *)ip2)[1];
        sumr += ip1r * ip2r + ip1i * ip2i;
        sumi += ip1r * ip2i - ip1i * ip2r;
    }
}
