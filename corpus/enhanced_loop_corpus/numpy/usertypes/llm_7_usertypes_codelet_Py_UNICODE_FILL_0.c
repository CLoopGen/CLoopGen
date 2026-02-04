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
    Py_ssize_t j;
    target[0] = value;
    for (j = 1; j < length; j++) {
        target[j] = target[j - 1]; // Introduce RAW dependency: each write depends on previous element's value
    }
}
