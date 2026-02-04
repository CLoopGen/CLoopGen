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



void loop() {
    for (n = 0; n < nblocks; n++) {
        a = ABCD[3];
        b = ABCD[2];
        c = ABCD[1];
        d = ABCD[0];
        X = (const uint32_t *)src + n * 16;

        // Unroll the loop and reorganize memory access to be consecutive in T and S, with precomputed indices
        const uint32_t *X_base = X;
        uint32_t idx, offset;
        uint8_t s_row, s_col;

        // Process rounds 0-63 in groups using strided access pattern on X via indirect index mapping
        int indices[64];
        for (int i = 0; i < 16; i++) indices[i] = i;           // First 16: direct order
        for (int i = 16; i < 32; i++) indices[i] = (1 + 5 * i) & 15;
        for (int i = 32; i < 48; i++) indices[i] = (5 + 3 * i) & 15;
        for (int i = 48; i < 64; i++) indices[i] = (7 * i) & 15;

        for (int i = 0; i < 64; i++) {
            idx = i;
            offset = indices[idx];

            t = S[idx >> 4][idx & 3];
            uint32_t data = ((const union unaligned_32 *)(X_base + offset))->l;

            if (idx < 16) {
                a += T[idx] + (d ^ (b & (c ^ d))) + data;
                a = b + (a << t | a >> (32 - t));
                // Rotate variables: a->b->c->d->a
                uint32_t temp = d; d = c; c = b; b = a; a = temp;
            } else if (idx < 32) {
                a += T[idx] + ((d & b) | (~d & c)) + data;
                a = b + (a << t | a >> (32 - t));
                uint32_t temp = d; d = c; c = b; b = a; a = temp;
            } else if (idx < 48) {
                a += T[idx] + (b ^ c ^ d) + data;
                a = b + (a << t | a >> (32 - t));
                uint32_t temp = d; d = c; c = b; b = a; a = temp;
            } else {
                a += T[idx] + (c ^ (b | ~d)) + data;
                a = b + (a << t | a >> (32 - t));
                uint32_t temp = d; d = c; c = b; b = a; a = temp;
            }
        }

        ABCD[0] += d;
        ABCD[1] += c;
        ABCD[2] += b;
        ABCD[3] += a;
    }
}
