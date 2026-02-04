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
    // This variant writes the value at every second index, effectively halving the number of iterations
    // and leaving gaps in the target array (assuming other logic handles the rest).
    Py_ssize_t step = 2;
    for (i = 0; i < length; i += step) {
        target[i] = value;
    }
}
