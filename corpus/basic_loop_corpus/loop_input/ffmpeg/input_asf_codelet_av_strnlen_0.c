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
    size_t data_size = 64 << 20; // 64 MB to target ~0.01 sec runtime on modern CPU
    buffer = (char *)calloc(data_size, sizeof(char));
    if (!buffer) {
        exit(1);
    }
    // Fill with non-zero except one null at the end to ensure loop runs through most of data
    memset(buffer, 'A', data_size - 1);
    buffer[data_size - 1] = '\0';

    s = buffer;
    len = data_size;
    i = 0;
}