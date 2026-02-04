#include <stdio.h>

#include <inttypes.h>

extern uint8_t *dst;
extern uint8_t *src;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *d = dst + len - 1;
    for (; len > 0; len--) {
        *d-- = *src++;
        if (d < dst) break;
    }
}
