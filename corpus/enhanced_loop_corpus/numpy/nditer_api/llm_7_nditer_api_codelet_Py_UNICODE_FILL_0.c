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
    Py_ssize_t limit = (length + step - 1) / step;

    for (i = 0; i < limit; i++) {
        Py_ssize_t idx1 = i * step;
        if (idx1 < length) {
            target[idx1] = value;
        }
        Py_ssize_t idx2 = i * step + 1;
        if (idx2 < length) {
            target[idx2] = value;
        }
    }
}
