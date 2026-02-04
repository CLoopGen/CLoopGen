#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t nlm;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < nlm; ++i) {
        for (j = 0; j < 5; ++j) {
            uint32_t x = (i ^ j) * 3217;
            x += (x << 3) + (x >> 2);
        }
    }
}
