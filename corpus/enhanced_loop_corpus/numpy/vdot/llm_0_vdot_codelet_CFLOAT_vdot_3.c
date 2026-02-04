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
    npy_intp j;
    for (j = 0; j < n; j++) {
        i = j;
        const float ip1r = ((float *)(ip1 + i * is1))[0];
        const float ip1i = ((float *)(ip1 + i * is1))[1];
        const float ip2r = ((float *)(ip2 + i * is2))[0];
        const float ip2i = ((float *)(ip2 + i * is2))[1];
        sumr += ip1r * ip2r + ip1i * ip2i;
        sumi += ip1r * ip2i - ip1i * ip2r;
    }
}
