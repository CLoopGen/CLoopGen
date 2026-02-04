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
    // Variant 1: Increased computational intensity by unrolling the loop 2x and reducing trip count
    npy_intp i_end = n - 1;
    for (i = 0; i < i_end; i += 2, ip1 += 2*is1, ip2 += 2*is2) {
        // First element
        const float ip1r1 = ((float *)ip1)[0];
        const float ip1i1 = ((float *)ip1)[1];
        const float ip2r1 = ((float *)ip2)[0];
        const float ip2i1 = ((float *)ip2)[1];
        sumr += ip1r1 * ip2r1 + ip1i1 * ip2i1;
        sumi += ip1r1 * ip2i1 - ip1i1 * ip2r1;

        // Second element
        const float ip1r2 = ((float *)(ip1 + is1))[0];
        const float ip1i2 = ((float *)(ip1 + is1))[1];
        const float ip2r2 = ((float *)(ip2 + is2))[0];
        const float ip2i2 = ((float *)(ip2 + is2))[1];
        sumr += ip1r2 * ip2r2 + ip1i2 * ip2i2;
        sumi += ip1r2 * ip2i2 - ip1i2 * ip2r2;
    }
    // Handle remaining element if n is odd
    if (i < n) {
        const float ip1r = ((float *)ip1)[0];
        const float ip1i = ((float *)ip1)[1];
        const float ip2r = ((float *)ip2)[0];
        const float ip2i = ((float *)ip2)[1];
        sumr += ip1r * ip2r + ip1i * ip2i;
        sumi += ip1r * ip2i - ip1i * ip2r;
        i++;
        ip1 += is1;
        ip2 += is2;
    }
}
