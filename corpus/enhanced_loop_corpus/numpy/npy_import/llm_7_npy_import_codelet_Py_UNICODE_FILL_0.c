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
    Py_ssize_t step = 2;
    Py_ssize_t j;
    for (j = 0; j < length; j += step) {
        target[j] = value;
        if (j + 1 < length) {
            target[j + 1] = value;
        }
    }
}
