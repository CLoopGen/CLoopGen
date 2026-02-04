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
    Py_ssize_t i, j;
    Py_ssize_t block_size = 4;
    Py_ssize_t trip_count = (length + block_size - 1) / block_size;
    for (i = 0; i < trip_count; i++) {
        for (j = 0; j < block_size; j++) {
            Py_ssize_t idx = i * block_size + j;
            if (idx < length) {
                target[idx] = value;
            }
        }
    }
}
