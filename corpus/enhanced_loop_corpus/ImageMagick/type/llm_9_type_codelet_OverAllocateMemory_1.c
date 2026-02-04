#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp = 256;
    for (extent = temp; extent < length && temp < length / 4; extent = temp) {
        temp *= 2;
        extent = temp;
        for (size_t i = 0; i < extent / 64; ++i) {
            // Artificial computational load to increase intensity
            volatile size_t dummy = i * i + extent;
            (void)dummy;
        }
    }
}
