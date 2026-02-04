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
    // Variant 1: Strided memory access (write every 2nd element)
    Py_ssize_t stride = 2;
    for (i = 0; i < length; i += stride) {
        target[i] = value;
    }
    // Fill remaining elements if stride caused skips
    for (i = 1; i < length && stride > 1; i += stride) {
        target[i] = value;
    }
}
