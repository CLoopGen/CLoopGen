#include <stdio.h>

#include <inttypes.h>

typedef unsigned int DES_LONG;

extern const DES_LONG DES_SPtrans[8][64];
extern DES_LONG l;
extern DES_LONG r;
extern DES_LONG t;
extern DES_LONG u;
extern DES_LONG *s;
extern int j;
extern DES_LONG E0;
extern DES_LONG E1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing s[0], s[2], ..., s[30] with fixed even indices,
    // use a strided access pattern via an index array to simulate non-unit stride indirectly.
    // This helps test memory subsystem behavior under non-sequential access.

    const int indices[16] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30}; // Predefined even strides

    for (j = 0; j < 25; j++) {
        for (int round = 0; round < 16; round++) {
            int base_idx = indices[round]; // Simulate strided access through lookup
            DES_LONG tmp;
            t = r ^ (r >> 16L);
            u = t & E0;
            t &= E1;
            tmp = (u << 16);
            u ^= r ^ s[base_idx];
            u ^= tmp;
            tmp = (t << 16);
            t ^= r ^ s[base_idx + 1];
            t ^= tmp;

            t = ({
                register unsigned int ret;
                asm ("rorl %1,%0" : "=r" (ret) : "I" (4), "0" (t) : "cc");
                ret;
            });
            l ^= DES_SPtrans[0][(u >> 2L) & 63] ^
                DES_SPtrans[2][(u >> 10L) & 63] ^
                DES_SPtrans[4][(u >> 18L) & 63] ^
                DES_SPtrans[6][(u >> 26L) & 63] ^
                DES_SPtrans[1][(t >> 2L) & 63] ^
                DES_SPtrans[3][(t >> 10L) & 63] ^
                DES_SPtrans[5][(t >> 18L) & 63] ^
                DES_SPtrans[7][(t >> 26L) & 63];

            // Swap l and r after each half-round (mimicking original alternation)
            if ((round & 1) == 0) { // Even rounds update l -> affect r next
                t = l;
                l = r;
                r = t;
            } else if (round == 15) {
                // Final swap to preserve state symmetry
                t = l;
                l = r;
                r = t;
            }
        }
    }
}
