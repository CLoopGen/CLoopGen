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
    npy_intp doubled_n = n * 2;
    for (npy_intp i = 0; i < doubled_n; i += 2) {
        // Reduced effective trip count with fewer iterations but same coverage
        volatile char val = ptr[i * (stride / 2)];
        (void)val;
    }
}
