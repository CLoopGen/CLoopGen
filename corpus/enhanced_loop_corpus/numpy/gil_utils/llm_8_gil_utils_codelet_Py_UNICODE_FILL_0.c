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
    Py_ssize_t i = 0;
    Py_ssize_t limit = length - (length % 4);
    for (; i < limit; i += 4) {
        target[i]     = value;
        target[i + 1] = value;
        target[i + 2] = value;
        target[i + 3] = value;
    }
    for (; i < length; i++) {
        target[i] = value;
    }
}
