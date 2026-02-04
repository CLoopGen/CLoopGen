#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int i;
extern int ncol;
extern uint32_t *pal;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < ncol; i++) {
        const uint8_t *src = (const uint8_t *)(buf + 3 * i);
        uint32_t val = src[0];
        val = (val << 8) | src[1];
        val = (val << 8) | src[2];
        val |= 0xFF000000;  // Add alpha channel setting (extra computation)
        *pal++ = val;
    }
}
