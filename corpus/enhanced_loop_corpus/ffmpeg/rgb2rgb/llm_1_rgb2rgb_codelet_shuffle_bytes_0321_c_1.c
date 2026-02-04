#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int idx;
extern  uint8_t *s;
extern uint8_t *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 2; outer++) {
        for (; idx < 15 && (outer * 15 + idx) < 30; idx += 4) {
            register unsigned int v = *(const uint32_t *)&s[idx], g = v & 16711935;
            v &= 4278255360U;
            *(uint32_t *)&d[idx] = (v >> 16) + g + (v << 16);
        }
    }
}
