#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

static char *internal_s;
static const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU

void init_vars() {
    internal_s = (char*)malloc(data_size);
    if (!internal_s) {
        exit(1);
    }

    // Fill with non-zero bytes to simulate string data
    memset(internal_s, 'A', data_size - 1);
    // Place null terminator near the end to ensure loop runs long but terminates
    internal_s[data_size - 1] = '\0';

    s = internal_s;
    len = data_size;
    i = 0;
}