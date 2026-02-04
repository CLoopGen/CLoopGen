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
    Py_ssize_t limit = (length % 2 == 0) ? length : length - 1;
    for (i = 0; i < limit; i += step) {
        target[i] = value;
        target[i + 1] = value;
    }
    if (length % 2 == 1) {
        target[length - 1] = value;
    }
}
