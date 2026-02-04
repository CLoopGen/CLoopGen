#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

static char *buffer;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; // 128 MB
    buffer = (char *)malloc(data_size);
    if (!buffer) {
        exit(1);
    }

    for (size_t j = 0; j < data_size - 1; j++) {
        buffer[j] = 'x'; 
    }
    buffer[data_size - 1] = '\0';

    s = buffer;
    len = data_size;
}