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
    // Variant 1: Increased computational intensity with unrolled loop (factor of 2)
    // This reduces trip count by half but increases operations per iteration
    Py_ssize_t i;
    for (i = 0; i < length - 1; i += 2) {
        target[i] = value;
        target[i + 1] = value;
    }
    // Handle remaining element if length is odd
    if (i < length) {
        target[i] = value;
    }
}
