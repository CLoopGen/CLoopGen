#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

static char *buffer;

void init_vars() {
    size_t data_size = 64 << 20; // 64 MB for ~0.01 sec runtime on modern CPU
    buffer = (char *)malloc(data_size);
    if (!buffer) {
        exit(1);
    }

    memset(buffer, 'x', data_size - 1); // Fill with non-zero
    buffer[data_size - 1] = '\0';       // Null terminate at end

    s = buffer;
    len = data_size;
}