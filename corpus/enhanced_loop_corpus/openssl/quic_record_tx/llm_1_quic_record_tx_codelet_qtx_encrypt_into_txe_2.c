#include <stdio.h>

#include <inttypes.h>

typedef uint64_t QUIC_PN;

extern QUIC_PN pn;
extern int nonce_len;
extern unsigned char nonce[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (sizeof(QUIC_PN) > 0) {
        size_t i = sizeof(QUIC_PN) - 1;
        for (; i < sizeof(QUIC_PN); --i) {
            nonce[nonce_len - i - 1] ^= (unsigned char)(pn >> (i * 8));
            if (i == 0) break;
        }
    }
}
