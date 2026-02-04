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
    // Variant 2: Reduced effective trip count by writing every 4th element, then filling in reverse
    // This increases arithmetic per iteration but reduces forward iterations
    Py_ssize_t step = 4;
    Py_ssize_t i;

    // First pass: write at stride of 4
    for (i = 0; i < length; i += step) {
        target[i] = value;
    }

    // Second pass: fill in the gaps from high to low index
    for (i = length - 1; i >= 0; i--) {
        if (target[i] != value) {
            target[i] = value;
        }
    }
}
