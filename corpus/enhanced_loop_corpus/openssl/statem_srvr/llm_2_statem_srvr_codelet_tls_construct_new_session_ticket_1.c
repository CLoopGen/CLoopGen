#include <stdio.h>

#include <inttypes.h>

extern unsigned char tick_nonce[8];
extern size_t i;
extern uint64_t nonce;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive forward memory access with index reversal
    unsigned char temp[8];
    for (size_t idx = 0; idx < 8; idx++) {
        temp[idx] = (unsigned char)(nonce >> (8 * idx));
    }
    for (i = 0; i < 8; i++) {
        tick_nonce[i] = temp[7 - i];
    }
}
