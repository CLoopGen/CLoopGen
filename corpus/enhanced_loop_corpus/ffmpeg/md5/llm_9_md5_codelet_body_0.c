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
    // Increase computational intensity: process each block with deeper arithmetic and more memory accesses
    for (n = 0; n < nblocks; n++) {
        a = ABCD[3];
        b = ABCD[2];
        c = ABCD[1];
        d = ABCD[0];
        X = (const uint32_t *)src + n * 16;

        // Simulate higher trip count effect via internal loop over expanded schedule
        for (int round = 0; round < 64; round++) {
            t = S[round >> 4][round & 3];

            // Rotate active variables cyclically every 4 steps
            uint32_t *v1, *v2, *v3, *tmp;
            switch ((round / 4) % 4) {
                case 0: v1 = &d; v2 = &b; v3 = &c; tmp = &a; break;
                case 1: v1 = &c; v2 = &a; v3 = &b; tmp = &d; break;
                case 2: v1 = &b; v2 = &d; v3 = &a; tmp = &c; break;
                default: v1 = &a; v2 = &c; v3 = &d; tmp = &b; break;
            }

            // Compute message index with nonlinear access pattern
            uint32_t word;
            if (round < 16)
                word = ((const union unaligned_32 *)(X + (round & 15)))->l;
            else if (round < 32)
                word = ((const union unaligned_32 *)(X + ((1 + 5*round) & 15)))->l;
            else if (round < 48)
                word = ((const union unaligned_32 *)(X + ((5 + 3*round) & 15)))->l;
            else
                word = ((const union unaligned_32 *)(X + ((7*round) & 15)))->l;

            // Apply function based on round
            uint32_t f;
            if (round < 16)
                f = (*v1) ^ ((*v2) & ((*v3) ^ (*v1)));
            else if (round < 32)
                f = ((*v1) & (*v2)) | (~(*v1) & (*v3));
            else if (round < 48)
                f = (*v1) ^ (*v2) ^ (*v3);
            else
                f = (*v2) ^ ((*v1) | ~(*v3));

            // Update accumulator
            (*tmp) += T[round] + f + word;
            (*tmp) = *v2 + ((*tmp) << t | (*tmp) >> (32 - t));
        }

        ABCD[0] += d;
        ABCD[1] += c;
        ABCD[2] += b;
        ABCD[3] += a;
    }
}
