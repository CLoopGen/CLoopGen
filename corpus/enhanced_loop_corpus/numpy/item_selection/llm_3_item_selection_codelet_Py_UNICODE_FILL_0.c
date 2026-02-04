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
    // Variant 2: Reverse consecutive memory access
    // This variant writes the value starting from the end of the array down to the beginning.
    // Maintains correctness while reversing the access pattern.
    Py_ssize_t i;
    for (i = length - 1; i >= 0; i--) {
        target[i] = value;
    }
}
