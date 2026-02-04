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
    // Variant 2: Strided memory access with reverse traversal
    char *current = (char *)p + (n - 1) * stride;
    for (npy_intp i = 0; i < n; i++, current -= stride) {
        char val = *current;  // Access in reverse order with original stride
        // Could perform computation on val
    }
}
