#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t src_size1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < src_size1 * 2; i++) {
        if (i % 3 == 0) {
            uint32_t x = (i + 1) * 5;
            x = (x >> 1) + (x << 2);
        }
    }
}
