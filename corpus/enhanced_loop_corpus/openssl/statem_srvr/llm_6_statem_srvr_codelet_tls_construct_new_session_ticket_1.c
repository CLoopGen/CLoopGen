#include <stdio.h>

#include <inttypes.h>

extern unsigned char tick_nonce[8];
extern size_t i;
extern uint64_t nonce;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp_nonce = nonce;
    for (i = 0; i < 8; i++) {
        tick_nonce[i] = (unsigned char)(temp_nonce & 255);
        temp_nonce >>= 8;
    }
}
