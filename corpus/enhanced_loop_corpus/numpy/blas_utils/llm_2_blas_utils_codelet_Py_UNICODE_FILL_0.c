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
    // Variant 1: Strided memory access (stride of 2)
    // This writes to every second element in the first forward pass,
    // then handles the odd indices in a second pass if needed.
    // Ensures all elements are covered when length is even or odd.

    Py_ssize_t stride = 2;
    for (i = 0; i < length; i += stride) {
        target[i] = value;
    }
    for (i = 1; i < length; i += stride) {
        target[i] = value;
    }
}
