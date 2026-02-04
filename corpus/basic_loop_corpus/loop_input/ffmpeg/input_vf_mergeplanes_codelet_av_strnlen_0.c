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
    
    // Fill with non-zero bytes to ensure loop runs through most of the buffer
    memset(buffer, 'A', data_size - 1); // All 'A'
    buffer[data_size - 1] = '\0';       // Null terminate at end

    s = buffer;
    len = data_size;
    i = 0;
}