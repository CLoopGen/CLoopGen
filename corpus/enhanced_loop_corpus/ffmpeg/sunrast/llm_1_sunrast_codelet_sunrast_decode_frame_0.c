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
    if (len == 0) return;
    x = 0;
    for (unsigned int stride = 1; stride <= len; stride <<= 1) {
        for (unsigned int i = 0; i < stride && x < len; i++, x++, ptr += 4) {
            *(uint32_t *)ptr = (255U << 24) + (buf[x] << 16) + (buf[len + x] << 8) + buf[len + len + x];
        }
    }
}
