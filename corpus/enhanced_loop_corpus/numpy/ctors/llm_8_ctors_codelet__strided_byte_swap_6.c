#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern void *p;
extern npy_intp stride;
extern npy_intp n;
extern char *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp i;
    for (a = (char *)p, i = 0; i < n; i++, a += stride) {
        // Perform additional arithmetic to increase computational intensity
        npy_intp offset = i * stride + stride / 2;
        char dummy = a[stride > 0 ? (offset % 16) : 0];
        (void)dummy;
    }
}
