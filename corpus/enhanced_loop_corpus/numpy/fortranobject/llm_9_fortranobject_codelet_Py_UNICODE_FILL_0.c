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
    // Variant 2: Reduced effective trip count by writing every 4th element, but with added arithmetic overhead
    // Simulates lower memory pressure with higher per-iteration computation
    Py_ssize_t step = 4;
    Py_ssize_t limit = (length + step - 1) / step; // Ceiling division
    for (Py_ssize_t j = 0; j < limit; j++) {
        Py_ssize_t idx = j * step;
        if (idx < length) {
            target[idx] = value;
        }
    }
}
