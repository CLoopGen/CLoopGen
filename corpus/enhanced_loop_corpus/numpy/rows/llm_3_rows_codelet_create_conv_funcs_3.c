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
    // Variant 2: Indirect memory access via pointer arithmetic with reversed traversal
    Py_ssize_t *p = usecols + num_fields - 1;
    for (; i < num_fields; i++, p--) {
        if (column == *p) {
            column = p - usecols;
            break;
        }
    }
}
