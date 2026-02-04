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
    // Variant 2: Strided memory access with stride of 4 (access every 4th element first, then next phase)
    Py_ssize_t stride = 4;
    Py_ssize_t phase, i;
    for (phase = 0; phase < stride; phase++) {
        for (i = phase; i < length; i += stride) {
            target[i] = value;
        }
    }
}
