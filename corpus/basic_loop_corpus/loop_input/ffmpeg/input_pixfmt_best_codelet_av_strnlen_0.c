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
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    buffer = (char*)malloc(data_size);
    if (!buffer) exit(1);

    // Fill with non-zero bytes to simulate string data
    memset(buffer, 'A', data_size - 1);
    buffer[data_size - 1] = '\0'; // null-terminator to satisfy s[i] condition

    s = buffer;
    len = data_size;
}