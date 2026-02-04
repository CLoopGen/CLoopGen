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

void init_vars() {
    len = 128 * 1024 * 1024; // 128 MB to target ~0.01 sec on modern CPUs
    buffer = (char *)malloc(len);
    if (!buffer) {
        exit(1);
    }
    // Fill with non-zero except at the end to force loop to scan nearly all
    memset(buffer, 'A', len - 1);
    buffer[len - 1] = '\0'; // Ensure loop terminates at last element
    s = buffer;
    i = 0;
}