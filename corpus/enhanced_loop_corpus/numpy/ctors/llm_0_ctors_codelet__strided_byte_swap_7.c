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
    char *temp_a;
    npy_intp temp_n;
    for (a = (char *)p; n > 0; n--) {
        temp_a = a;
        temp_n = stride;
        for (npy_intp i = 0; i < stride; i++) {
            temp_a++;
        }
        a = temp_a;
    }
}
