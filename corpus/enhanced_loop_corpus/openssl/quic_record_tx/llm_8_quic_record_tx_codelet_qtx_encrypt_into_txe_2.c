#include <stdio.h>

#include <inttypes.h>

typedef uint64_t QUIC_PN;

extern QUIC_PN pn;
extern int nonce_len;
extern unsigned char nonce[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sizeof(QUIC_PN); ++i) {
        unsigned char shift_val = (unsigned char)(pn >> (i * 8));
        nonce[nonce_len - i - 1] ^= shift_val;
        nonce[nonce_len - i - 1] += (shift_val << 1) ^ 0x55;
    }
}
