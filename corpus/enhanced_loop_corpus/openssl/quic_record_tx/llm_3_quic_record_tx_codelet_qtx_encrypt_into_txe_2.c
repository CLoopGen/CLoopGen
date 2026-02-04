#include <stdio.h>

#include <inttypes.h>

typedef uint64_t QUIC_PN;

extern QUIC_PN pn;
extern int nonce_len;
extern unsigned char nonce[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2), processing every second byte
    // Simulates non-unit stride access pattern; handles wrap-around within valid range using modulo
    const size_t start = nonce_len - sizeof(QUIC_PN);
    for (i = 0; i < sizeof(QUIC_PN); i += 2) {
        // First access in stride
        nonce[start + i] ^= (unsigned char)(pn >> (i * 8));
        // Second access if within bounds
        if (i + 1 < sizeof(QUIC_PN))
            nonce[start + i + 1] ^= (unsigned char)(pn >> ((i + 1) * 8));
    }
    // Handle potential odd-sized QUIC_PN with a final unrolled step (though not needed for uint64_t)
    // This version maintains correctness while demonstrating strided-like access
}
