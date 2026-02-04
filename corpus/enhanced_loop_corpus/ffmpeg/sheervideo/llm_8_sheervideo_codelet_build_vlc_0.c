#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *len;
extern int count;
extern uint32_t codes[1024];
extern uint8_t bits[1024];
extern uint16_t syms[1024];
extern uint64_t _usr_index;
extern int i;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 1: Increased computational intensity with unrolled operations and additional arithmetic
    // Trip count effectively reduced by processing two iterations per loop step with extra bit manipulations
    int limit = (count / 2) * 2;  // Ensure even count for safe unrolling
    for (i = 0; i < limit; i += 2) {
        uint8_t shift1 = 32 - len[i];
        uint8_t shift2 = 32 - len[i + 1];
        uint64_t step1 = 1ULL << shift1;
        uint64_t step2 = 1ULL << shift2;

        codes[i]     = (uint32_t)(index >> shift1);
        bits[i]      = len[i];
        syms[i]      = i;
        index       += step1;

        codes[i + 1] = (uint32_t)(index >> shift2);
        bits[i + 1]  = len[i + 1];
        syms[i + 1]  = i + 1;
        index       += step2;
    }
    // Handle remaining element if count is odd
    if (count > limit) {
        uint8_t shift = 32 - len[limit];
        codes[limit] = (uint32_t)(index >> shift);
        bits[limit] = len[limit];
        syms[limit] = limit;
        index += 1ULL << shift;
    }
}
