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
    // Variant 1: Consecutive memory access with unrolled stride simulation
    // Instead of strided access (ptr += 4), we write 4 consecutive bytes at a time using memcpy-like pattern
    uint32_t temp;
    for (x = 0; x < len; x++) {
        temp = (255U << 24) + (buf[x] << 16) + (buf[len + x] << 8) + buf[2*len + x];
        __builtin_memcpy(ptr, &temp, sizeof(temp));
        ptr += 4;
    }
}
