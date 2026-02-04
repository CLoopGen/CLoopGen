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
    if (length > 0) {
        for (i = 0; i < 1; i++) {
            for (Py_ssize_t k = 0; k < length; k++) {
                target[k] = value;
            }
        }
    }
}
