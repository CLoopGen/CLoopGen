#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern unsigned int x;
extern uint8_t *ptr;
extern unsigned int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int outer;
    for (outer = 0; outer < len; outer++) {
        x = outer;
        *(uint32_t *)(ptr + 4*x) = (255U << 24) + (buf[x] << 16) + (buf[len + x] << 8) + buf[len + len + x];
    }
}
