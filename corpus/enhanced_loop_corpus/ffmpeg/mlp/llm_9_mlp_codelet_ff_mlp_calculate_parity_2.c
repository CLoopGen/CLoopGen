#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern uint32_t scratch;
extern  uint8_t *buf_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; buf < buf_end - 1; buf += 2)
        scratch ^= (uint32_t)(buf[0]) ^ (uint32_t)(buf[1]);
}
