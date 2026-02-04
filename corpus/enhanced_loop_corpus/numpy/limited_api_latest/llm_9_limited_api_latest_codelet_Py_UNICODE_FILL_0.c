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
    // Variant 2: Reduced effective trip count with stride-based access
    // Increases stride to reduce iterations, but only fills every k-th element
    // Then fills in the gaps in a second pass — increases memory accesses per arithmetic op
    const Py_ssize_t stride = 2;
    Py_ssize_t i;

    // First pass: fill with stride
    for (i = 0; i < length; i += stride) {
        target[i] = value;
    }

    // Second pass: fill in skipped elements
    for (i = 1; i < length; i += stride) {
        target[i] = value;
    }
}
