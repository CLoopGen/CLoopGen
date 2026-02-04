#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

char *p;
int n;
char *q;

static char *buffer;
static size_t data_size = 1 << 20; // 1MB

void init_vars() {
    if (buffer) return;

    buffer = (char *)malloc(data_size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        buffer[i] = (char)(i & 0xFF);
    }

    p = buffer;
    q = buffer + data_size - 1;
}