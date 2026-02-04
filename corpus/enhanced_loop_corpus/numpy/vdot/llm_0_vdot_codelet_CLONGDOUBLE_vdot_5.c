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
    npy_intp j;
    for (j = 0; j < n; j++) {
        i = j;
        const npy_longdouble ip1r = ((npy_longdouble *)ip1)[0];
        const npy_longdouble ip1i = ((npy_longdouble *)ip1)[1];
        const npy_longdouble ip2r = ((npy_longdouble *)ip2)[0];
        const npy_longdouble ip2i = ((npy_longdouble *)ip2)[1];
        tmpr += ip1r * ip2r + ip1i * ip2i;
        tmpi += ip1r * ip2i - ip1i * ip2r;
        ip1 += is1;
        ip2 += is2;
    }
}
