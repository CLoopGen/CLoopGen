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
    // Unroll factor of 3 with cleanup loop for remaining elements
    Py_ssize_t i = 0;
    Py_ssize_t remainder = length % 3;
    Py_ssize_t trip_count = length - remainder;

    for (; i < trip_count; i += 3) {
        target[i]     = value;
        target[i + 1] = value;
        target[i + 2] = value;
    }
    // Handle leftover elements
    for (; i < length; i++) {
        target[i] = value;
    }
}
