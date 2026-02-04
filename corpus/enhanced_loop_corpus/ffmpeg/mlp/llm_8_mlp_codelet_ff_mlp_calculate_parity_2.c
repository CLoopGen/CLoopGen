#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern uint32_t scratch;
extern  uint8_t *buf_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp1, temp2;
    for (; buf < buf_end - 7; buf += 8) {
        temp1 = *((const uint32_t *)buf);
        temp2 = *((const uint32_t *)(buf + 4));
        scratch ^= temp1 ^ temp2;
        scratch += temp1 & temp2;
    }
}
