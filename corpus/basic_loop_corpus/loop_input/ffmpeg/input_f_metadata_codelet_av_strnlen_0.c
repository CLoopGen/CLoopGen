#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *s;
size_t len;
size_t i;

static char *buffer;

void init_vars() {
    len = 134217728; // ~128 MB to target ~0.01 sec on modern CPU
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

void loop();