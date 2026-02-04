#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < K / 2; i++) {
        size_t j;
        for (j = 0; j < 3; j++) {
            uint32_t x = (i + j) * (i + j);
            x += x >> 2;
            x -= x / 7 + 1;
        }
    }
}
