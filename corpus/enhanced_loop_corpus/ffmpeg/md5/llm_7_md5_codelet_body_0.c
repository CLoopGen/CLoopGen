#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern  uint8_t S[4][4];
extern  uint32_t T[64];
extern uint32_t ABCD[4];
extern  uint8_t *src;
extern int nblocks;
extern int n;
extern  uint32_t *X;
extern uint32_t a;
extern uint32_t b;
extern uint32_t c;
extern uint32_t d;
extern uint32_t t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 0; n < nblocks; n++) {
    a = ABCD[3];
    b = ABCD[2];
    c = ABCD[1];
    d = ABCD[0];
    X = (const uint32_t *)src + n * 16;

    // Introduce loop-carried dependency via cumulative sum to modify execution order sensitivity
    uint32_t acc = 0;

    for (int i = 0; i < 64; i++) {
        uint32_t idx = i;
        t = S[idx >> 4][idx & 3];
        uint32_t x_idx = (i < 16) ? (i) :
                         (i < 32) ? ((1 + 5*i) & 15) :
                         (i < 48) ? ((5 + 3*i) & 15) :
                                    ((7*i) & 15);

        uint32_t data = ((const union unaligned_32 *)(X + x_idx))->l;

        // Accumulate into `acc` to create artificial loop-carried dependence
        acc ^= data;

        if (i % 4 == 0) {
            a += T[i] + (d ^ (b & (c ^ d))) + acc;
            a = b + (a << t | a >> (32 - t));
        } else if (i % 4 == 1) {
            d += T[i] + (c ^ (a & (b ^ c))) + acc;
            d = a + (d << t | d >> (32 - t));
        } else if (i % 4 == 2) {
            c += T[i] + (b ^ (d & (a ^ b))) + acc;
            c = d + (c << t | c >> (32 - t));
        } else {
            b += T[i] + (a ^ (c & (d ^ a))) + acc;
            b = c + (b << t | b >> (32 - t));
        }

        // Update state with modified round function using accumulated value
        acc = (acc << 11) | (acc >> 21); // Simple LFSR-like update
    }

    // Finalize with accumulated effects
    ABCD[0] += d + acc;
    ABCD[1] += c + acc;
    ABCD[2] += b + acc;
    ABCD[3] += a + acc;
}
}
