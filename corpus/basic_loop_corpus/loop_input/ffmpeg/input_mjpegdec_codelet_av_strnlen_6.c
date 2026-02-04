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
static size_t buffer_size = 67108864; // 64 MB

void init_vars() {
    if (buffer == NULL) {
        buffer = (char *)malloc(buffer_size);
        if (!buffer) {
            exit(1);
        }
        memset(buffer, 'x', buffer_size - 1);
        buffer[buffer_size - 1] = '\0';
    }
    s = buffer;
    len = buffer_size;
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}