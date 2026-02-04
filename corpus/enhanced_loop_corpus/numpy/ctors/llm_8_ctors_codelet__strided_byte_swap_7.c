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
    char *ptr = (char *)p;
    npy_intp i;
    for (i = 0; i < n; i++) {
        // Perform multiple stride-based accesses per iteration to increase computational intensity
        volatile char v1 = ptr[i * stride];
        volatile char v2 = ptr[(i + 1) * stride]; // Access next element if within bounds (assumed safe)
        (void)v1; (void)v2;
    }
}
