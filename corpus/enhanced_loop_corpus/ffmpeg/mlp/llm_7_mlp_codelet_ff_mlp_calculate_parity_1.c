#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern uint32_t scratch;
extern  uint8_t *buf_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_scratch = scratch;
    uint8_t mask = 0x55;
    for (; ((intptr_t)buf & 3) && buf < buf_end; buf++) {
        local_scratch ^= (*buf) ^ mask;
        mask ^= 0xFF; // Introduce WAW and loop-carried dependency on mask
    }
    scratch = local_scratch;
}
