#include <stdio.h>

#include <inttypes.h>

typedef uint64_t QUIC_PN;

extern QUIC_PN pn;
extern int nonce_len;
extern unsigned char nonce[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[8] = {nonce_len - 1, nonce_len - 2, nonce_len - 3, nonce_len - 4,
                         nonce_len - 5, nonce_len - 6, nonce_len - 7, nonce_len - 8};
    for (i = 0; i < sizeof(QUIC_PN); ++i)
        nonce[indices[i]] ^= (unsigned char)(pn >> (i * 8));
}
