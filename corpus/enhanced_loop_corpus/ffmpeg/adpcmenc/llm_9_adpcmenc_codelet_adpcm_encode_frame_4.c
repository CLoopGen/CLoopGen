#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int i;
extern uint8_t *dst;
extern uint8_t *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i += 1) {
        uint8_t high = buf[i] & 0xF0;
        uint8_t low = buf[i] & 0x0F;
        *dst++ = (high >> 4) | (low << 4);
        i++; 
        if (i >= n) break;
    }
}
