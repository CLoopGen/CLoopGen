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
    // Variant 2: Strided access with reverse traversal and alternating pattern
    char *base = (char *)p;
    npy_intp i;
    npy_intp offset = (n - 1) * stride;
    for (i = n - 1; i >= 0; i--, offset -= 2 * stride) {
        char val = base[offset + stride];  // Access using computed strided index
        (void)val;
    }
}
