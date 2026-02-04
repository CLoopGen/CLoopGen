#include <stdio.h>

#include <inttypes.h>

typedef uint64_t QUIC_PN;

extern QUIC_PN pn;
extern int nonce_len;
extern unsigned char nonce[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    QUIC_PN temp_pn = pn;
    for (i = 0; i < sizeof(QUIC_PN); ++i) {
        unsigned char extracted = (unsigned char)(temp_pn >> (i * 8));
        nonce[nonce_len - i - 1] ^= extracted;
    }
}
