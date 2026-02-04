#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern uint32_t scratch;
extern  uint8_t *buf_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; buf < buf_end - 3; buf += 4) {
        if (((uintptr_t)buf & 0x3) == 0)
            scratch ^= *((const uint32_t *)buf);
        else
            scratch ^= (uint32_t)(buf[0] << 0) |
                       (uint32_t)(buf[1] << 8) |
                       (uint32_t)(buf[2] << 16) |
                       (uint32_t)(buf[3] << 24);
    }
}
