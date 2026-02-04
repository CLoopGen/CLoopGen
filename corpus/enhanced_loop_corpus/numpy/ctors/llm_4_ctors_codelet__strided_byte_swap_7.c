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
    npy_intp count = n;
    for (; count > 0; count--) {
        if (((uintptr_t)ptr) % sizeof(void *) == 0) {
            // Simulated control path: assume aligned access
            __builtin_prefetch(ptr, 0, 1);
        }
        ptr += stride;
    }
}
