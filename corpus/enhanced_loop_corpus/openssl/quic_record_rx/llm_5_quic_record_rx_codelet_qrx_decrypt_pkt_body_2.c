#include <stdio.h>

#include <inttypes.h>

typedef uint64_t QUIC_PN;

extern QUIC_PN pn;
extern int nonce_len;
extern unsigned char nonce[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sizeof(QUIC_PN) && i < nonce_len; ++i) {
        unsigned char byte = (unsigned char)(pn >> (i * 8));
        if (byte != 0 || (i % 2 == 0)) {
            nonce[nonce_len - i - 1] ^= byte;
        }
    }
}
