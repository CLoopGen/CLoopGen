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
    npy_intp j, k;
    npy_intp half_n = n / 2;
    for (j = 0; j < half_n; j++) {
        // First element in pair
        i = j * 2;
        char *current_ip1 = ip1 + is1 * i;
        char *current_ip2 = ip2 + is2 * i;
        const double ip1r1 = ((double *)current_ip1)[0];
        const double ip1i1 = ((double *)current_ip1)[1];
        const double ip2r1 = ((double *)current_ip2)[0];
        const double ip2i1 = ((double *)current_ip2)[1];
        sumr += ip1r1 * ip2r1 + ip1i1 * ip2i1;
        sumi += ip1r1 * ip2i1 - ip1i1 * ip2r1;

        // Second element in pair
        current_ip1 += is1;
        current_ip2 += is2;
        const double ip1r2 = ((double *)current_ip1)[0];
        const double ip1i2 = ((double *)current_ip1)[1];
        const double ip2r2 = ((double *)current_ip2)[0];
        const double ip2i2 = ((double *)current_ip2)[1];
        sumr += ip1r2 * ip2r2 + ip1i2 * ip2i2;
        sumi += ip1r2 * ip2i2 - ip1i2 * ip2r2;
    }
    // Handle odd n
    if (n % 2 == 1) {
        i = n - 1;
        char *current_ip1 = ip1 + is1 * i;
        char *current_ip2 = ip2 + is2 * i;
        const double ip1r = ((double *)current_ip1)[0];
        const double ip1i = ((double *)current_ip1)[1];
        const double ip2r = ((double *)current_ip2)[0];
        const double ip2i = ((double *)current_ip2)[1];
        sumr += ip1r * ip2r + ip1i * ip2i;
        sumi += ip1r * ip2i - ip1i * ip2r;
    }
}
