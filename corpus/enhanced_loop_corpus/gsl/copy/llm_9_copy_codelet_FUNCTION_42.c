#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t src_size1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < src_size1 * 2; i++) {
        uint32_t x = (uint32_t)(i % 1024);
        uint32_t y = (x * x + 5) / (x + 1);
        y += (y ^ i) & 0xFF;
    }
}
