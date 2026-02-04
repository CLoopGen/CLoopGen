#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern uint32_t scratch;
extern  uint8_t *buf_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive 32-bit word access with alignment handling
    uint32_t *buf32 = (uint32_t*)(((intptr_t)buf + 3) & ~3); // Align to next 32-bit boundary
    uint8_t *buf8 = buf;

    // Handle initial unaligned bytes
    for (; buf8 < (uint8_t*)buf32 && buf8 < buf_end; buf8++)
        scratch ^= *buf8;

    // Process aligned 32-bit words
    for (; buf32 + 1 <= (uint32_t*)((intptr_t)buf_end & ~3); buf32++) {
        scratch ^= *buf32;
        scratch = __builtin_bswap32(scratch); // Add data transformation for realism
    }

    // Handle trailing bytes
    buf8 = (uint8_t*)buf32;
    for (; buf8 < buf_end; buf8++)
        scratch ^= *buf8;
}
