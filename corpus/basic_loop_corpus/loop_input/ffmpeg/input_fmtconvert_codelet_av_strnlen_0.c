#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *s;
size_t len;
size_t i;

static char *buffer;

void init_vars() {
    len = 134217728; // 128 MB to target ~0.01 sec runtime on modern CPU
    buffer = (char *)malloc(len);
    if (!buffer) {
        exit(1);
    }
    for (size_t idx = 0; idx < len - 1; idx++) {
        buffer[idx] = 'x'; 
    }
    buffer[len - 1] = '\0'; 
    s = buffer;
    i = 0;
}