#include <stdio.h>

#include <inttypes.h>

typedef uint64_t QUIC_PN;

extern QUIC_PN pn;
extern int nonce_len;
extern unsigned char nonce[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t k;
    const size_t shift_unit = 8;
    const size_t pn_size = sizeof(QUIC_PN);
    for (k = 0; k < pn_size * 2; k += 2) {
        if (k / 2 < pn_size) {
            size_t index = k / 2;
            unsigned char shifted = (unsigned char)(pn >> (index * shift_unit));
            nonce[nonce_len - index - 1] ^= shifted;
        }
    }
}
