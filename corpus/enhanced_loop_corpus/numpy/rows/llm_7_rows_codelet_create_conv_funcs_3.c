#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

extern Py_ssize_t num_fields;
extern  Py_ssize_t *usecols;
extern Py_ssize_t column;
extern Py_ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Py_ssize_t local_i = i;
    Py_ssize_t found = 0;
    for (; local_i < num_fields && !found; local_i++) {
        if (column == usecols[local_i]) {
            column = local_i;
            found = 1;
        }
    }
    i = local_i;
}
