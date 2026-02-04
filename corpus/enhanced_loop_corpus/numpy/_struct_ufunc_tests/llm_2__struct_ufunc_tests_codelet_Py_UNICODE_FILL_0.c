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
    // This writes to every second element in the first pass, then fills remaining if needed
    Py_ssize_t stride = 2;
    Py_ssize_t offset;

    for (offset = 0; offset < stride; offset++) {
        for (i = offset; i < length; i += stride) {
            target[i] = value;
        }
    }
}
