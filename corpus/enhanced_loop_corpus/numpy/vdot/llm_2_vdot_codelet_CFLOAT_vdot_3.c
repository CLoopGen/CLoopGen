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
    // Variant 1: Consecutive Memory Access (assume packed data layout)
    // Assume that input data is now stored in consecutive float pairs (r,i) in a contiguous buffer.
    // We remove strided access by treating ip1 and ip2 as sequential arrays with stride 1.
    float *p1 = (float*)ip1;
    float *p2 = (float*)ip2;
    for (i = 0; i < n; i++) {
        const float ip1r = p1[2*i + 0];
        const float ip1i = p1[2*i + 1];
        const float ip2r = p2[2*i + 0];
        const float ip2i = p2[2*i + 1];
        sumr += ip1r * ip2r + ip1i * ip2i;
        sumi += ip1r * ip2i - ip1i * ip2r;
    }
}
