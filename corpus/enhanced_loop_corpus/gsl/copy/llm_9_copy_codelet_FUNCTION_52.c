#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t src_size1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < src_size1 * 2; i++) {
        uint32_t a = i + 1;
        uint32_t b = i + 2;
        uint32_t c = a * b + (a - b);
    }
}
