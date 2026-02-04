#include <stdio.h>

#include <inttypes.h>

extern uint8_t *dst;
extern uint8_t *src;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t i = 0; i < len; i++) {
        dst[len - 1 - i] = src[i];
    }
}
