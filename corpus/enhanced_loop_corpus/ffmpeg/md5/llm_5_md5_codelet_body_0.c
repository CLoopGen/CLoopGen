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

        // Combine all operations into a single loop with computed function selection
        // Eliminate deep nesting and flatten control using lookup tables for F functions and message indices
        const uint8_t f_selector[64] = {
            0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,  // Stage 0-15: F = d^(b&(c^d))
            1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,  // Stage 16-31: F = (d&b)|(~d&c)
            2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2,  // Stage 32-47: F = b^c^d
            3,3,3,3, 3,3,3,3, 3,3,3,3, 3,3,3,3   // Stage 48-63: F = c^(b|~d)
        };

        const uint8_t index_formula[64] = {
            0,1,2,3, 4,5,6,7, 8,9,10,11, 12,13,14,15, // i & 15
            0,1,2,3, 4,5,6,7, 8,9,10,11, 12,13,14,15, // (1+5*i)&15
            0,1,2,3, 4,5,6,7, 8,9,10,11, 12,13,14,15, // (5+3*i)&15
            0,1,2,3, 4,5,6,7, 8,9,10,11, 12,13,14,15  // (7*i)&15
        };

        // Precomputed shifts to avoid recalculating complex expressions
        uint32_t inputs[64];
        for (int i = 0; i < 16; ++i)
            inputs[i] = ((const union unaligned_32 *)(X + i))->l;
        for (int i = 16; i < 32; ++i)
            inputs[i] = ((const union unaligned_32 *)(X + ((1 + 5*i) & 15)))->l;
        for (int i = 32; i < 48; ++i)
            inputs[i] = ((const union unaligned_32 *)(X + ((5 + 3*i) & 15)))->l;
        for (int i = 48; i < 64; ++i)
            inputs[i] = ((const union unaligned_32 *)(X + ((7*i) & 15)))->l;

        uint32_t A = a, B = b, C = c, D = d;

        for (int i = 0; i < 64; i++) {
            t = S[i >> 4][i & 3];

            uint32_t f;
            switch (f_selector[i]) {
                case 0: f = D ^ (B & (C ^ D)); break;
                case 1: f = (D & B) | (~D & C); break;
                case 2: f = B ^ C ^ D; break;
                case 3: f = C ^ (B | ~D); break;
            }

            if (i % 4 == 0) {
                A += T[i] + f + inputs[i];
                A = B + (A << t | A >> (32 - t));
            } else if (i % 4 == 1) {
                D += T[i] + f + inputs[i];
                D = A + (D << t | D >> (32 - t));
            } else if (i % 4 == 2) {
                C += T[i] + f + inputs[i];
                C = D + (C << t | C >> (32 - t));
            } else {
                B += T[i] + f + inputs[i];
                B = C + (B << t | B >> (32 - t));
            }
        }

        ABCD[0] += D;
        ABCD[1] += C;
        ABCD[2] += B;
        ABCD[3] += A;
    }
}
