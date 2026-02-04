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
    npy_intp outer;
    const npy_intp half_n = n / 2;
    for (outer = 0; outer < half_n; outer++) {
        // First half iteration
        i = outer;
        {
            const npy_longdouble ip1r = ((npy_longdouble *)ip1)[0];
            const npy_longdouble ip1i = ((npy_longdouble *)ip1)[1];
            const npy_longdouble ip2r = ((npy_longdouble *)ip2)[0];
            const npy_longdouble ip2i = ((npy_longdouble *)ip2)[1];
            tmpr += ip1r * ip2r + ip1i * ip2i;
            tmpi += ip1r * ip2i - ip1i * ip2r;
        }
        ip1 += is1;
        ip2 += is2;

        // Second half iteration
        i = outer + half_n;
        {
            const npy_longdouble ip1r = ((npy_longdouble *)ip1)[0];
            const npy_longdouble ip1i = ((npy_longdouble *)ip1)[1];
            const npy_longdouble ip2r = ((npy_longdouble *)ip2)[0];
            const npy_longdouble ip2i = ((npy_longdouble *)ip2)[1];
            tmpr += ip1r * ip2r + ip1i * ip2i;
            tmpi += ip1r * ip2i - ip1i * ip2r;
        }
        ip1 += is1;
        ip2 += is2;
    }

    // Handle odd n
    if (n % 2 != 0) {
        i = n - 1;
        const npy_longdouble ip1r = ((npy_longdouble *)ip1)[0];
        const npy_longdouble ip1i = ((npy_longdouble *)ip1)[1];
        const npy_longdouble ip2r = ((npy_longdouble *)ip2)[0];
        const npy_longdouble ip2i = ((npy_longdouble *)ip2)[1];
        tmpr += ip1r * ip2r + ip1i * ip2i;
        tmpi += ip1r * ip2i - ip1i * ip2r;
    }
}
