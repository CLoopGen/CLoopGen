#include <stdlib.h>
#include <stdint.h>

size_t length;
size_t extent;

void init_vars() {
    length = 1 << 28; // ~256MB of data to ensure loop runs ~0.01 sec
    extent = 0;
}

void loop();