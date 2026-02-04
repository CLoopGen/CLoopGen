#include <stdio.h>

#include <inttypes.h>

extern unsigned char tick_nonce[8];
extern size_t i;
extern uint64_t nonce;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_nonce = nonce;
    unsigned char temp_tick_nonce[8];
    for (i = 0; i < 8; i++) {
        temp_tick_nonce[7 - i] = (unsigned char)(local_nonce >> (i * 8));
    }
    for (i = 0; i < 8; i++) {
        tick_nonce[i] = temp_tick_nonce[i];
    }
}
