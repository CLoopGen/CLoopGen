#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *s;
size_t len;
size_t i;

static char *buffer;

void init_vars() {
    len = 16777216; // 16MB to ensure ~0.01 sec runtime on modern CPUs
    buffer = (char *)malloc(len);
    if (!buffer) {
        exit(1);
    }
    for (size_t j = 0; j < len - 1; j++) {
        buffer[j] = 'x'; 
    }
    buffer[len - 1] = '\0'; 

    s = buffer;
    i = 0;
}