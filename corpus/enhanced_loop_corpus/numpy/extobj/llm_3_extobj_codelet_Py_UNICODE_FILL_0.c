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
    // Variant 2: Reverse consecutive access with pointer arithmetic
    // Traverse from end to beginning using pointer offset
    Py_UNICODE *base = target;
    for (i = length - 1; i >= 0; i--) {
        base[i] = value;
    }
}
