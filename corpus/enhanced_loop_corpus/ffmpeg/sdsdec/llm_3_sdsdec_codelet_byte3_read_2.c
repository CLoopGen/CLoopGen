#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint32_t *dst;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Consecutive memory access with pointer arithmetic to improve locality
    uint8_t *s = src;
    uint32_t *d = dst;
    for (i = 0; i < 120; i += 3, s += 3) {
        unsigned int sample;
        // Access source consecutively via pointer, improving cache behavior
        sample = ((unsigned int)s[0] << 25) | ((unsigned int)s[1] << 18) | ((unsigned int)s[2] << 11);
        d[i / 3] = sample;
    }
}
