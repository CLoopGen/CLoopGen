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
    // Variant 1: Consecutive memory access with reverse traversal
    for (i = count - 1; i >= 0; i--) {
        int rev_i = count - 1 - i;  // Reverse index for forward data flow in reverse loop
        codes[rev_i] = index >> (32 - len[rev_i]);
        bits[rev_i] = len[rev_i];
        syms[rev_i] = rev_i;
        index += 1ULL << (32 - len[rev_i]);
    }
}
