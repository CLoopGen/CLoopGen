#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef ssize_t Py_ssize_t;

Py_ssize_t num_fields;
Py_ssize_t *usecols;
Py_ssize_t column;
Py_ssize_t i;

void init_vars() {
    // Target data size: aim for ~64MB for usecols array to ensure non-trivial runtime
    num_fields = (64 * 1024 * 1024) / sizeof(Py_ssize_t);  // ~64MB array

    usecols = (Py_ssize_t*)calloc(num_fields, sizeof(Py_ssize_t));
    if (!usecols) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize usecols with unique increasing values to simulate realistic data
    for (Py_ssize_t idx = 0; idx < num_fields; idx++) {
        usecols[idx] = idx + 1;
    }

    // Set column to a value that will be found at the end of the array to maximize loop iterations
    column = num_fields;  // so that `column == usecols[i]` only when i = num_fields-1 and usecols[i] = num_fields
    if (num_fields > 0) {
        usecols[num_fields - 1] = num_fields;
    }

    // Initialize loop index
    i = 0;
}