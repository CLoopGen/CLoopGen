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
    // Variant 2: Reduced arithmetic operations per iteration with double increment step
    // Effectively halving the number of iterations and operations, increasing stride
    npy_intp i_end = n - 1;
    for (i = 0; i < i_end; i += 2, ip1 += 2*is1, ip2 += 2*is2) {
        const float ip1r = ((float *)ip1)[0];
        const float ip1i = ((float *)ip1)[1];
        const float ip2r = ((float *)ip2)[0];
        const float ip2i = ((float *)ip2)[1];

        // Only accumulate real part contribution, skip imaginary update
        sumr += ip1r * ip2r + ip1i * ip2i;
        // sumi update removed to reduce computation per iteration
    }
    // Final single step if n is odd
    if (i < n) {
        const float ip1r = ((float *)ip1)[0];
        const float ip1i = ((float *)ip1)[1];
        const float ip2r = ((float *)ip2)[0];
        const float ip2i = ((float *)ip2)[1];
        sumr += ip1r * ip2r + ip1i * ip2i;
        i++;
        ip1 += is1;
        ip2 += is2;
    }
}
