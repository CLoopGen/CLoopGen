#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *buf;
int ix;

static char *internal_buf;

void init_vars() {
    size_t data_size = 1 << 20; // 1MB
    internal_buf = (char*)calloc(data_size, sizeof(char));
    if (!internal_buf) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    buf = internal_buf + data_size - 1;
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}

__attribute__((destructor))
static void destructor() {
    free(internal_buf);
}