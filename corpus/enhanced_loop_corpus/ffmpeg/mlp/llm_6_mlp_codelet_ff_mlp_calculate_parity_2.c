#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern uint32_t scratch;
extern  uint8_t *buf_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp = scratch;
    for (; buf < buf_end - 7; buf += 8) {
        temp ^= *((const uint32_t *)buf);
        temp ^= *((const uint32_t *)(buf + 4));
    }
    scratch = temp;
}
