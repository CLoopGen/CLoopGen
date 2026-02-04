#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int srcWidth;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Forward Access with Pointer Arithmetic
    // Use pointer arithmetic to traverse src and dst in a consecutive forward pattern
    uint8_t *s = src;
    uint8_t *d = dst + 1;  // Start writing to dst[1]
    int limit = srcWidth - 1;
    for (x = 0; x < limit; x++) {
        d[0] = (3 * s[0] + s[1]) >> 2;
        d[1] = (s[0] + 3 * s[1]) >> 2;
        s++;
        d += 2;
    }
}
