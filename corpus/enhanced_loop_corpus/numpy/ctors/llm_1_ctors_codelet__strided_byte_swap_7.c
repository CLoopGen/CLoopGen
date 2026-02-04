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
    for (a = (char *)p; n > 0; ) {
        for (npy_intp i = 0; i < 1 && n > 0; i++, n--, a += stride) {
        }
    }
}
