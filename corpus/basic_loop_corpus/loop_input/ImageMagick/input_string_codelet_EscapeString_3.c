#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *source;
char escape;
char *q;
char *p;

static char *buffer_source;
static char *buffer_q;

void init_vars() {
    const size_t data_size = 64 << 20; // 64 MB

    buffer_source = (char *)malloc(data_size);
    if (!buffer_source) exit(1);

    buffer_q = (char *)malloc(2 * data_size);
    if (!buffer_q) exit(1);

    for (size_t i = 0; i < data_size - 1; i++) {
        buffer_source[i] = (rand() % 32) == 0 ? '\\' : (rand() % 95 + 32);
    }
    buffer_source[data_size - 1] = '\x00';

    source = buffer_source;
    escape = '"';
    q = buffer_q;
}

__attribute__((destructor))
static void cleanup() {
    free(buffer_source);
    free(buffer_q);
}