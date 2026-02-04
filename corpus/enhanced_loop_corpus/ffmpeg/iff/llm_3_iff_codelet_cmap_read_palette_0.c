#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *pal;
extern int count;
extern int i;
extern  uint8_t * palette;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed iteration and fixed offset stepping
    int stride = 3;
    for (i = count - 1; i >= 0; i--) {
        int idx = i * stride;
        uint8_t r = ((const uint8_t *)(palette))[idx];
        uint8_t g = ((const uint8_t *)(palette))[idx + 1];
        uint8_t b = ((const uint8_t *)(palette))[idx + 2];
        pal[i] = 4278190080U | ((r << 16) | (g << 8) | b);
    }
}
