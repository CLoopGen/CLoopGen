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
    // Fill every second element first, then fill the gaps
    Py_ssize_t stride = 2;
    Py_ssize_t start;

    for (start = 0; start < stride; start++) {
        for (i = start; i < length; i += stride) {
            target[i] = value;
        }
    }
}
