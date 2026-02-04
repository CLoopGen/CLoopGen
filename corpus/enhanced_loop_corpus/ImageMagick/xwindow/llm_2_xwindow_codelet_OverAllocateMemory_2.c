#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Introduce a strided access pattern via an array index with stride 4
        volatile uint8_t dummy;
        uint8_t *base = (uint8_t*)malloc(extent * 4);
        if (!base) continue;
        for (size_t i = 0; i < extent; i += 4) {
            dummy = base[i]; // Strided access: every 4th element
        }
        free(base);
    }
}
