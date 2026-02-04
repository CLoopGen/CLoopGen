#include <stdio.h>

#include <inttypes.h>

extern uint8_t *dst;
extern uint8_t *src;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i = len;
    for (; i > 0; ) {
        i--;
        *dst-- = *src++;
    }
}
