#include <stdio.h>

#include <inttypes.h>

extern char *dest;
extern size_t bytes;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 1;
    for (; i < bytes; i += step) {
        dest[i] = 0;
        step = (i % 4 == 0) ? 2 : 1; // Occasionally increase stride, creating variable arithmetic intensity
    }
}
