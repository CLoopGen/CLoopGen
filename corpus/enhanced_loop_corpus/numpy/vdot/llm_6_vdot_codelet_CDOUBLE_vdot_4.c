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
    double local_sumr = 0.0;
    double local_sumi = 0.0;
    char *temp_ip1 = ip1;
    char *temp_ip2 = ip2;
    for (i = 0; i < n; i++) {
        const double ip1r = ((double *)temp_ip1)[0];
        const double ip1i = ((double *)temp_ip1)[1];
        const double ip2r = ((double *)temp_ip2)[0];
        const double ip2i = ((double *)temp_ip2)[1];
        local_sumr += ip1r * ip2r + ip1i * ip2i;
        local_sumi += ip1r * ip2i - ip1i * ip2r;
        temp_ip1 += is1;
        temp_ip2 += is2;
    }
    sumr += local_sumr;
    sumi += local_sumi;
}
