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
    
    // Fill with non-zero bytes up to near the end, then a zero to trigger loop termination
    size_t fill_size = data_size - 1;
    memset(buffer, 'A', fill_size);
    buffer[fill_size] = 0; // null terminator
    
    s = buffer;
    len = data_size;
    i = 0;
}