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
    uint64_t local_index = index;
    for (i = 0; i < count; i++) {
        uint8_t current_len = len[i];
        uint64_t shift = 32 - current_len;
        codes[i] = (uint32_t)(local_index >> shift);
        bits[i] = current_len;
        syms[i] = i;
        local_index += 1ULL << shift;
    }
    index = local_index;
}
