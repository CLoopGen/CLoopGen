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
    // Variant 1: Consecutive memory access (unit stride, forward traversal)
    char *base = (char *)p;
    npy_intp step = 1;
    for (npy_intp i = 0; i < n; i++) {
        char val = base[i * step];  // Simulated access with unit stride
        // Could perform computation on val
    }
}
