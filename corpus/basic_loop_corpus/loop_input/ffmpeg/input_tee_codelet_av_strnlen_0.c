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
    size_t data_size = 128 << 20; // 128 MB
    buffer = (char*)calloc(data_size, sizeof(char));
    if (!buffer) {
        exit(1);
    }
    
    size_t fill_len = data_size - 1;
    for (size_t idx = 0; idx < fill_len; ++idx) {
        buffer[idx] = 'x';
    }
    buffer[fill_len] = '\0';

    s = buffer;
    len = data_size;
}