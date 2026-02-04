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
    for (x = 0; x < len; x += 2, ptr += 8) {
        if (x + 1 < len) {
            *(uint32_t *)ptr = (255U << 24) + (buf[x] << 16) + (buf[len + x] << 8) + buf[2*len + x];
            *(uint32_t *)(ptr + 4) = (255U << 24) + (buf[x+1] << 16) + (buf[len + x+1] << 8) + buf[2*len + x+1];
        } else {
            *(uint32_t *)ptr = (255U << 24) + (buf[x] << 16) + (buf[len + x] << 8) + buf[2*len + x];
        }
    }
}
