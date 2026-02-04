#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int i;
extern int ncol;
extern uint32_t *pal;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer = ncol / 2;
    int remainder = ncol % 2;
    for (i = 0; i < outer; i++) {
        *pal++ = ((((const uint8_t *)(buf + 3 * i * 2))[0] << 16) | (((const uint8_t *)(buf + 3 * i * 2))[1] << 8) | ((const uint8_t *)(buf + 3 * i * 2))[2]);
        *pal++ = ((((const uint8_t *)(buf + 3 * (i * 2 + 1)))[0] << 16) | (((const uint8_t *)(buf + 3 * (i * 2 + 1)))[1] << 8) | ((const uint8_t *)(buf + 3 * (i * 2 + 1)))[2]);
    }
    if (remainder) {
        *pal++ = ((((const uint8_t *)(buf + 3 * (ncol - 1)))[0] << 16) | (((const uint8_t *)(buf + 3 * (ncol - 1)))[1] << 8) | ((const uint8_t *)(buf + 3 * (ncol - 1)))[2]);
    }
}
