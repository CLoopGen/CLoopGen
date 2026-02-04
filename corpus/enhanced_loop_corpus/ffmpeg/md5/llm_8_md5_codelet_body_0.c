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

        // Unroll the outer loop by processing two rounds per iteration with reduced conditionals
        for (int i = 0; i < 64; i += 2) {
            // First round: index i
            t = S[i >> 4][i & 3];
            if (i % 4 == 0) a += T[i] + ((d ^ (b & (c ^ d))) + ((const union unaligned_32 *)(X + (i & 15)))->l);
            else if (i < 16) a += T[i] + ((c ^ (a & (b ^ c))) + ((const union unaligned_32 *)(X + (i & 15)))->l);
            else if (i < 32) a += T[i] + (((c & a) | (~c & b)) + ((const union unaligned_32 *)(X + ((1 + 5*i) & 15)))->l);
            else if (i < 48) a += T[i] + ((a ^ b ^ c) + ((const union unaligned_32 *)(X + ((5 + 3*i) & 15)))->l);
            else a += T[i] + ((b ^ (a | ~c)) + ((const union unaligned_32 *)(X + ((7*i) & 15)))->l);
            a = b + (a << t | a >> (32 - t));

            // Second round: index i+1, update next variable in cycle
            int j = i + 1;
            if (j >= 64) break;
            t = S[j >> 4][j & 3];
            if (j % 4 == 1) d += T[j] + ((a ^ (c & (d ^ a))) + ((const union unaligned_32 *)(X + (j & 15)))->l);
            else if (j < 16) d += T[j] + ((b ^ (d & (a ^ b))) + ((const union unaligned_32 *)(X + (j & 15)))->l);
            else if (j < 32) d += T[j] + (((b & d) | (~b & a)) + ((const union unaligned_32 *)(X + ((1 + 5*j) & 15)))->l);
            else if (j < 48) d += T[j] + ((d ^ a ^ b) + ((const union unaligned_32 *)(X + ((5 + 3*j) & 15)))->l);
            else d += T[j] + ((a ^ (d | ~b)) + ((const union unaligned_32 *)(X + ((7*j) & 15)))->l);
            d = a + (d << t | d >> (32 - t));
        }

        ABCD[0] += d;
        ABCD[1] += c;
        ABCD[2] += b;
        ABCD[3] += a;
    }
}
