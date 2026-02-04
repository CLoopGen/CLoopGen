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
    npy_intp step = 2;
    for (i = 0; i < n; i += step, ip1 += is1 * step, ip2 += is2 * step) {
        if (i + 1 >= n) break;
        const npy_longdouble ip1r0 = ((npy_longdouble *)ip1)[0];
        const npy_longdouble ip1i0 = ((npy_longdouble *)ip1)[1];
        const npy_longdouble ip2r0 = ((npy_longdouble *)ip2)[0];
        const npy_longdouble ip2i0 = ((npy_longdouble *)ip2)[1];
        tmpr += ip1r0 * ip2r0 + ip1i0 * ip2i0;
        tmpi += ip1r0 * ip2i0 - ip1i0 * ip2r0;

        const npy_longdouble ip1r1 = ((npy_longdouble *)(ip1 + is1))[0];
        const npy_longdouble ip1i1 = ((npy_longdouble *)(ip1 + is1))[1];
        const npy_longdouble ip2r1 = ((npy_longdouble *)(ip2 + is2))[0];
        const npy_longdouble ip2i1 = ((npy_longdouble *)(ip2 + is2))[1];
        tmpr += ip1r1 * ip2r1 + ip1i1 * ip2i1;
        tmpi += ip1r1 * ip2i1 - ip1i1 * ip2r1;
    }
}
