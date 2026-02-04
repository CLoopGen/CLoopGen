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
    npy_intp s = stride;
    npy_intp count = n;
    for (; count > 0; count--) {
        // Introduce a temporary that accumulates changes (WAW dependency introduced)
        char temp = *ptr;
        temp ^= 0xFF;           // Modify local copy
        *ptr = temp;            // Write back — creates WAW on *ptr across iterations if stride=0, otherwise weak dependence
        ptr += s;
    }
}
