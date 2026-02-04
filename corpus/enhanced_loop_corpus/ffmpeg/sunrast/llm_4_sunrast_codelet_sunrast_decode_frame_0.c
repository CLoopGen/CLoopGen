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
    x = 0;
    if (len == 0) return;
    do {
        *(uint32_t *)ptr = (255U << 24) | ((uint32_t)buf[x] << 16) | ((uint32_t)buf[len + x] << 8) | buf[2*len + x];
        x++;
        ptr += 4;
    } while (x < len);
}
