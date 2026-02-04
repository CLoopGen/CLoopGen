#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < 32; ++n) {
        size_t idx = n % 16;
        out[idx] ^= iv[idx] ^ (out[(idx + 8) % 16] & iv[(idx + 12) % 16]);
    }
}
