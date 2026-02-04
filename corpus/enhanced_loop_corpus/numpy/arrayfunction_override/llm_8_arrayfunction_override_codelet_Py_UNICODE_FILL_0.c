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
    // Variant 1: Increased computational intensity with unrolled loop (tripled arithmetic operations per iteration)
    // Unroll by factor of 3 to reduce loop overhead and increase operation density
    Py_ssize_t i;
    for (i = 0; i + 2 < length; i += 3) {
        target[i]     = value;
        target[i + 1] = value;
        target[i + 2] = value;
    }
    // Handle remaining elements
    for (; i < length; i++) {
        target[i] = value;
    }
}
