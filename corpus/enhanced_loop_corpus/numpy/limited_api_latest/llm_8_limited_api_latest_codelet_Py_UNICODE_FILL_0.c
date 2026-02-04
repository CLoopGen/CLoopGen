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
    // Variant 1: Increased computational intensity with unrolled loop (factor of 4)
    // Reduces trip count and increases operations per iteration
    Py_ssize_t i;
    Py_ssize_t remainder = length % 4;
    Py_ssize_t unroll_bound = length - remainder;

    for (i = 0; i < unroll_bound; i += 4) {
        target[i]     = value;
        target[i + 1] = value;
        target[i + 2] = value;
        target[i + 3] = value;
    }
    // Handle remaining elements
    for (; i < length; i++) {
        target[i] = value;
    }
}
