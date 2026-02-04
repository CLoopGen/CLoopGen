#include <stdio.h>

#include <inttypes.h>

extern unsigned char tick_nonce[8];
extern size_t i;
extern uint64_t nonce;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (write every second element in two passes)
    uint64_t n = nonce;
    // First pass: write to even indices in reverse order
    for (i = 4; i > 0; i--) {
        tick_nonce[2*(i-1)] = (unsigned char)(n & 255);
        n >>= 8;
    }
    // Second pass: write to odd indices in reverse order
    for (i = 4; i > 0; i--) {
        tick_nonce[2*(i-1)+1] = (unsigned char)(n & 255);
        n >>= 8;
    }
}
