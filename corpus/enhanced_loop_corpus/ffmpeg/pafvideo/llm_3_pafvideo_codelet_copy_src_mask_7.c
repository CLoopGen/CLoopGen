#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern uint8_t mask;
extern  uint8_t *src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed iteration and offset indexing
    uint8_t *d = dst;
    uint8_t *s = src;
    int w = width;
    uint8_t m = mask;

    for (i = 3; i >= 0; i--) {
        int shift1 = i;
        int shift2 = i + 4;
        if (m & (1 << shift2))
            d[3 - i] = s[3 - i];
        if (m & (1 << shift1))
            d[w + 3 - i] = s[w + 3 - i];
    }
}
