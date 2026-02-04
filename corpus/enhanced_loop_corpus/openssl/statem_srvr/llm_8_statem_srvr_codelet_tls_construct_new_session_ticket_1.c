#include <stdio.h>

#include <inttypes.h>

extern unsigned char tick_nonce[8];
extern size_t i;
extern uint64_t nonce;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 8; i > 0; i -= 2) {
        tick_nonce[i - 1] = (unsigned char)(nonce & 255);
        tick_nonce[i - 2] = (unsigned char)((nonce >> 8) & 255);
        nonce >>= 16;
    }
}
