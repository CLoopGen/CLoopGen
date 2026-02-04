#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *out;
size_t size;
size_t i;
unsigned char *q;
char c;

static unsigned char *buffer;

void init_vars() {
    size = 512 * 1024;  // 512 KB data size for ~0.01 sec runtime estimate
    buffer = (unsigned char *)malloc(size);
    if (!buffer) {
        exit(1);
    }
    out = buffer;
    q = buffer + size - 1;
}

__attribute__((destructor))
static void cleanup() {
    free(buffer);
}