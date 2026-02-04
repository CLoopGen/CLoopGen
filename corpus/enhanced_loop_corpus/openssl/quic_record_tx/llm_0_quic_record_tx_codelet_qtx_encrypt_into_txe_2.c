#include <stdio.h>

#include <inttypes.h>

typedef uint64_t QUIC_PN;

extern QUIC_PN pn;
extern int nonce_len;
extern unsigned char nonce[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < sizeof(QUIC_PN); ++outer) {
        for (size_t inner = 0; inner < 1; ++inner) {
            nonce[nonce_len - outer - 1] ^= (unsigned char)(pn >> (outer * 8));
        }
    }
}
