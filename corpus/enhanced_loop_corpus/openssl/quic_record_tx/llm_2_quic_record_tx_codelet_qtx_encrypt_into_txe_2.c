#include <stdio.h>

#include <inttypes.h>

typedef uint64_t QUIC_PN;

extern QUIC_PN pn;
extern int nonce_len;
extern unsigned char nonce[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive forward memory access with reversed index mapping
    // Instead of accessing nonce backwards, we reverse the iteration order and use forward indexing
    size_t idx = nonce_len - sizeof(QUIC_PN);
    for (i = 0; i < sizeof(QUIC_PN); ++i)
        nonce[idx + i] ^= (unsigned char)(pn >> ((sizeof(QUIC_PN) - 1 - i) * 8));
}
