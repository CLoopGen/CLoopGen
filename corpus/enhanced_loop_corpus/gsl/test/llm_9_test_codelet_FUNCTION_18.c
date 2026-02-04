#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t x, y;
    for (i = 0; i < 32; i++) {
        for (x = 0; x < 32; x++) {
            for (y = 0; y < 32; y++) {
                if ((x * y) % 17 == i % 13) {
                    break;
                }
            }
        }
    }
}
