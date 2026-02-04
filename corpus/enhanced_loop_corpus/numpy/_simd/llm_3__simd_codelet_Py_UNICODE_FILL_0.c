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
    // Variant 2: Indirect memory access using an index map (simulated via arithmetic)
    // Simulates accessing elements in a non-sequential order: reverse traversal
    Py_ssize_t i;
    for (i = 0; i < length; i++) {
        target[length - 1 - i] = value;
    }
}
