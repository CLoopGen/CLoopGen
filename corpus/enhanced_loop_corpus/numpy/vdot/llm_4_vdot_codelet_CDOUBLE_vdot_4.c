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
    for (i = 0; i < n; i++, ip1 += is1, ip2 += is2) {
        const double ip1r = ((double *)ip1)[0];
        const double ip1i = ((double *)ip1)[1];
        const double ip2r = ((double *)ip2)[0];
        const double ip2i = ((double *)ip2)[1];
        if (ip1r != 0 || ip1i != 0 || ip2r != 0 || ip2i != 0) {
            sumr += ip1r * ip2r + ip1i * ip2i;
            sumi += ip1r * ip2i - ip1i * ip2r;
        }
    }
}
