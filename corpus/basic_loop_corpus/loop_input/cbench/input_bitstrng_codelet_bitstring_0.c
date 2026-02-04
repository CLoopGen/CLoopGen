#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

char *str;
int i;
int j;

static char *internal_str_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB for ~0.01s runtime on modern CPU
    internal_str_buffer = (char *)malloc(data_size);
    if (!internal_str_buffer) {
        exit(1);
    }
    str = internal_str_buffer;
    j = data_size;
}