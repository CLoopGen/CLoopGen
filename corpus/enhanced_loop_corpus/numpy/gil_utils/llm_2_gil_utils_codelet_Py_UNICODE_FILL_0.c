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
    // Fills every second element with 'value', then loops again for odd indices if needed
    Py_ssize_t stride = 2;
    Py_ssize_t remainder = length % stride;

    for (i = 0; i < length; i += stride) {
        target[i] = value;
        if (i + 1 < length) {
            target[i + 1] = value;
        }
    }
}
