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
    Py_ssize_t local_value = (Py_ssize_t)value;
    for (i = 0; i < length; i++) {
        target[i] = (Py_UNICODE)(local_value ^ i); // Introduce RAW dependency: each write depends on i and original value
        local_value = local_value; // Preserve to prevent optimization; creates artificial WAW-free pattern with modified semantics still valid
    }
}
