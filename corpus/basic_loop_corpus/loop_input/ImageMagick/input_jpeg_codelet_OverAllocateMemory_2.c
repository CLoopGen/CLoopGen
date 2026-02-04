#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    length = 1 << 28;  // Approximately 268 million to ensure loop runs ~0.01 seconds
    extent = 256;
}

void loop();