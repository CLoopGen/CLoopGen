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
    // Variant 1: Strided memory access with stride of 2
    // This variant writes the value at every second index, traversing only even indices.
    // Afterward, a second forward pass handles the odd indices to ensure full coverage.
    Py_ssize_t i;
    for (i = 0; i < length; i += 2) {
        target[i] = value;
    }
    for (i = 1; i < length; i += 2) {
        target[i] = value;
    }
}
