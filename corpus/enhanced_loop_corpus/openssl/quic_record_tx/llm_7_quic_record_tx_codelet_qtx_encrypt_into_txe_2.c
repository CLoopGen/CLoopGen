#include <stdio.h>

#include <inttypes.h>

typedef uint64_t QUIC_PN;

extern QUIC_PN pn;
extern int nonce_len;
extern unsigned char nonce[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    QUIC_PN local_pn = pn;
    size_t offset = nonce_len - sizeof(QUIC_PN);
    for (i = 0; i < sizeof(QUIC_PN); ++i) {
        size_t idx = offset + i;
        unsigned char val = (unsigned char)(local_pn >> ((sizeof(QUIC_PN) - 1 - i) * 8));
        nonce[idx] ^= val;
    }
}
