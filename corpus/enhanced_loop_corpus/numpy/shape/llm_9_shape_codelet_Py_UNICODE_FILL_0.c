#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef wchar_t Py_UNICODE;

typedef ssize_t Py_ssize_t;

extern Py_UNICODE *target;
extern Py_UNICODE value;
extern Py_ssize_t length;
extern Py_ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Py_ssize_t i, j;
    Py_ssize_t unroll_factor = 4;
    Py_ssize_t remainder = length % unroll_factor;
    
    for (i = 0; i < remainder; i++) {
        target[i] = value;
    }
    
    for (j = 0; j < (length - remainder); j += unroll_factor) {
        target[j] = value;
        target[j + 1] = value;
        target[j + 2] = value;
        target[j + 3] = value;
    }
}
