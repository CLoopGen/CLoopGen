#include <stdio.h>

#include <inttypes.h>

typedef uint64_t QUIC_PN;

extern QUIC_PN pn;
extern int nonce_len;
extern unsigned char nonce[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t expanded_trip_count = sizeof(QUIC_PN) * 2;
    for (i = 0; i < expanded_trip_count; ++i) {
        size_t j = i / 2;
        if (i % 2 == 0)
            nonce[nonce_len - j - 1] ^= (unsigned char)(pn >> (j * 8));
        else
            nonce[nonce_len - j - 1] ^= (unsigned char)((pn >> (j * 8)) >> 4);
    }
}
