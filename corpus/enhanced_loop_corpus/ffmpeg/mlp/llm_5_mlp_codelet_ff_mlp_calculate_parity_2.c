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
        const uint32_t *aligned = (const uint32_t *)buf;
        if (aligned != NULL && ((uintptr_t)aligned & 0x3) == 0)
            scratch ^= *aligned;
        else
            continue;
    }
}
