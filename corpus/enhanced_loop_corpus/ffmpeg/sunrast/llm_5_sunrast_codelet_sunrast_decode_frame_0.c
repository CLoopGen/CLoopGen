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
    for (x = 0; x < len; x++) {
        if (x % 2 == 0) {
            *(uint32_t *)ptr = (255U << 24) | ((uint32_t)buf[x] << 16) | ((uint32_t)buf[len + x] << 8) | buf[2*len + x];
        } else {
            *(uint32_t *)ptr = (uint32_t)buf[x] | ((uint32_t)buf[len + x] << 8) | ((uint32_t)buf[2*len + x] << 16) | (255U << 24);
        }
        ptr += 4;
    }
}
