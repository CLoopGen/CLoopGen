#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    length = 1 << 28; // 256MB worth of data, large enough to make loop run ~0.01s
    extent = 0;
}

void loop();