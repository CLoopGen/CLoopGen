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
    // Also adjusts trip count to handle remainder safely
    Py_ssize_t i;
    Py_ssize_t n = length;
    for (i = 0; i < n - 1; i += 2) {
        target[i] = value;
        target[i + 1] = value;
    }
    // Handle remaining element if length is odd
    if (i < n) {
        target[i] = value;
    }
}
