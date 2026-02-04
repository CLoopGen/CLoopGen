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
    for (i = 0; i < n; i++) {
        uint8_t val1 = buf[i] ^ 0xFF;
        uint8_t val2 = buf[n + i] & 0x0F;
        *dst++ = (val1 << 4) | val2;
        *dst++ = (val2 << 4) | (val1 & 0x0F);
    }
    n *= 2;
}
