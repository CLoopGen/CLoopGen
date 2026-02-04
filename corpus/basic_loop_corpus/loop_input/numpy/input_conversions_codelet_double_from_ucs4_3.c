#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint32_t Py_UCS4;

Py_UCS4 *str;
Py_UCS4 *end;
char *c;

static Py_UCS4 *str_buffer;
static char *c_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01 sec runtime
    str_buffer = (Py_UCS4 *)calloc(data_size, sizeof(Py_UCS4));
    c_buffer = (char *)malloc(data_size * sizeof(char));
    if (!str_buffer || !c_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < data_size - 1; i++) {
        str_buffer[i] = (i % 128); // ASCII-range values
    }
    str_buffer[data_size - 1] = 128; // trigger break condition

    str = str_buffer;
    end = str_buffer + data_size;
    c = c_buffer;
}