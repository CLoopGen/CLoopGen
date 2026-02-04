#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern uint32_t scratch;
extern  uint8_t *buf_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive byte-wise access instead of 32-bit word access
    for (; buf < buf_end - 3; buf++)
        scratch ^= *buf;
}
