#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t i = 0; i < 8; i++) {
        for (size_t j = 0; j < 4; j++) {
            volatile uint64_t x = i * j + (i + j) * 2;
            volatile uint64_t y = x ^ (i | j);
        }
    }
}
