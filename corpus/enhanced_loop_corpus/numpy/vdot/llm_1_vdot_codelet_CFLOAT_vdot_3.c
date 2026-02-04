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
extern float sumr;
extern float sumi;
extern npy_intp i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp j, k;
    const npy_intp half_n = n / 2;
    const npy_intp remainder = n % 2;

    for (j = 0; j < half_n; j++) {
        i = j * 2;
        // First element in pair
        {
            const float ip1r = ((float *)ip1)[0];
            const float ip1i = ((float *)ip1)[1];
            const float ip2r = ((float *)ip2)[0];
            const float ip2i = ((float *)ip2)[1];
            sumr += ip1r * ip2r + ip1i * ip2i;
            sumi += ip1r * ip2i - ip1i * ip2r;
            ip1 += is1;
            ip2 += is2;
        }
        // Second element in pair
        {
            const float ip1r = ((float *)ip1)[0];
            const float ip1i = ((float *)ip1)[1];
            const float ip2r = ((float *)ip2)[0];
            const float ip2i = ((float *)ip2)[1];
            sumr += ip1r * ip2r + ip1i * ip2i;
            sumi += ip1r * ip2i - ip1i * ip2r;
            ip1 += is1;
            ip2 += is2;
        }
    }

    // Handle leftover element if n is odd
    for (k = 0; k < remainder; k++) {
        i = n - 1;
        const float ip1r = ((float *)ip1)[0];
        const float ip1i = ((float *)ip1)[1];
        const float ip2r = ((float *)ip2)[0];
        const float ip2i = ((float *)ip2)[1];
        sumr += ip1r * ip2r + ip1i * ip2i;
        sumi += ip1r * ip2i - ip1i * ip2r;
    }
}
