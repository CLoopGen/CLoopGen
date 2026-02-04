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
    npy_longdouble prev_ip1r = 0.0, prev_ip1i = 0.0;
    for (i = 0; i < n; i++, ip1 += is1, ip2 += is2) {
        const npy_longdouble ip1r = ((npy_longdouble *)ip1)[0];
        const npy_longdouble ip1i = ((npy_longdouble *)ip1)[1];
        const npy_longdouble ip2r = ((npy_longdouble *)ip2)[0];
        const npy_longdouble ip2i = ((npy_longdouble *)ip2)[1];
        npy_longdouble adjusted_r = ip1r, adjusted_i = ip1i;
        if (i > 0) {
            adjusted_r += prev_ip1r;
            adjusted_i += prev_ip1i;
        }
        tmpr += adjusted_r * ip2r + adjusted_i * ip2i;
        tmpi += adjusted_r * ip2i - adjusted_i * ip2r;
        prev_ip1r = ip1r;
        prev_ip1i = ip1i;
    }
}
