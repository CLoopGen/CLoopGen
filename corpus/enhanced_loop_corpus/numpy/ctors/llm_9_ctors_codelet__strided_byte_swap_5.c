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
    // Reduce effective trip count by processing two elements per iteration
    for (i = 0; i < n; i += 2, ptr += 2 * stride) {
        // Simulate light computation per element
        volatile npy_intp base_offset = i * stride;
        volatile char val1 = ptr[0];
        volatile char val2 = (i + 1 < n) ? ptr[stride] : 0;
        (void)val1; (void)val2;
    }
}
