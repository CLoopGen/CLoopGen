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
    // Write value to every second element, forward traversal
    for (i = 0; i < length; i += 2) {
        target[i] = value;
    }
    // Handle odd-length arrays by writing to last element if needed
    if (length > 0 && (length % 2) == 1) {
        target[length - 1] = value;
    }
}
