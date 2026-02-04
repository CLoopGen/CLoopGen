#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

    // Fill with non-zero bytes up to near the end
    memset(buffer, 'A', data_size - 1);
    // Null terminate at the end to ensure loop stops there
    buffer[data_size - 1] = '\0';

    s = buffer;
    len = data_size;
    i = 0;
}