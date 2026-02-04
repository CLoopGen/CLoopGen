#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2054; i += 2) {
        volatile size_t x = i * i + 3 * i - 5;
        volatile size_t y = (x >> 1) ^ (i << 2);
    }
}
