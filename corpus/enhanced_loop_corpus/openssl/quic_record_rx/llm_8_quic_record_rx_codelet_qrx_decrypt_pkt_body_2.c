#include <stdio.h>

#include <inttypes.h>

typedef uint64_t QUIC_PN;

extern QUIC_PN pn;
extern int nonce_len;
extern unsigned char nonce[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = 0; j < sizeof(QUIC_PN); ++j) {
        unsigned char temp = (unsigned char)(pn >> (j * 8));
        nonce[nonce_len - j - 1] ^= temp;
    }
}
