#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *content;
char *p;

static char *data_buffer;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; // 128 MB
    data_buffer = (char *)malloc(data_size);
    if (!data_buffer) {
        exit(1);
    }

    // Fill with non-terminating characters except at the end
    memset(data_buffer, 'a', data_size - 1);
    data_buffer[data_size - 1] = '\x00'; // Ensure loop stops at null terminator

    content = data_buffer;
    p = NULL;
}

__attribute__((destructor))
static void cleanup() {
    free(data_buffer);
}