#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int n;
char *s;
char *e;
char tc;

static char *buffer;
static size_t buffer_size;

void init_vars() {
    buffer_size = 134217728; // 128 MB
    buffer = (char *)malloc(buffer_size);
    if (!buffer) {
        exit(1);
    }

    memset(buffer, 'a', buffer_size);

    n = buffer_size - 1;
    s = buffer;
    e = buffer + n;

    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < buffer_size; i++) {
        buffer[i] = (char)('a' + rand() % 26);
    }
}