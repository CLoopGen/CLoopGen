#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *p;
int hi;
int i;

static char *buffer;
static size_t data_size = 1 << 20; // 1MB of data

void init_vars() {
    buffer = (char *)malloc(data_size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size - 1; idx++) {
        buffer[idx] = (char)(33 + (idx % 94)); // printable ASCII chars from '!' to '~'
    }
    buffer[data_size - 1] = 0; // null-terminate to satisfy loop condition

    p = buffer;
    hi = 0;
    i = 0;
}