#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

static char *internal_s_buffer;

void init_vars() {
    len = 16777216; // ~16MB to target ~0.01 sec on modern CPU
    internal_s_buffer = (char *)malloc(len);
    if (!internal_s_buffer) {
        exit(1);
    }
    memset(internal_s_buffer, 'x', len - 1);
    internal_s_buffer[len - 1] = '\0'; // Ensure loop terminates at last element
    s = internal_s_buffer;
}