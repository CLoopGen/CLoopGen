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
    uint8_t multiplier = 3;
    for (; buf < buf_end; buf++) {
        local_scratch ^= (*buf * multiplier) + (local_scratch >> 5);
        multiplier ^= *buf;
    }
    scratch = local_scratch;
}
