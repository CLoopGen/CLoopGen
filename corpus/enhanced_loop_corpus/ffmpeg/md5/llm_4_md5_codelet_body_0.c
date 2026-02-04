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

        // Unroll first 4 rounds with simplified control: remove nested ifs, precompute conditions
        for (int i = 0; i < 4; i++) {
            t = S[i >> 4][i & 3];
            a += T[i];
            uint32_t word_index = (i < 16) ? (i & 15) : ((1 + 5 * i) & 15);
            uint32_t f = (i < 16) ? (d ^ (b & (c ^ d))) : ((d & b) | (~d & c));
            a += f + (((const union unaligned_32 *)(X + word_index))->l);
            a = b + (a << t | a >> (32 - t));
            // Rotate variables: a becomes d, d becomes c, etc.
            uint32_t temp = a; a = d; d = c; c = b; b = temp;
        }

        // Remaining rounds from 4 to 63: use direct indexing and eliminate redundant condition checks
        for (int i = 4; i < 64; i++) {
            t = S[i >> 4][i & 3];

            if (i % 4 == 0) {
                a += T[i];
                uint32_t word_index, f;
                if (i < 16) {
                    word_index = (i & 15);
                    f = d ^ (b & (c ^ d));
                } else if (i < 32) {
                    word_index = ((1 + 5 * i) & 15);
                    f = (d & b) | (~d & c);
                } else if (i < 48) {
                    word_index = ((5 + 3 * i) & 15);
                    f = b ^ c ^ d;
                } else {
                    word_index = ((7 * i) & 15);
                    f = c ^ (b | ~d);
                }
                a += f + (((const union unaligned_32 *)(X + word_index))->l);
                a = b + (a << t | a >> (32 - t));
            } else if (i % 4 == 1) {
                d += T[i];
                uint32_t word_index, f;
                if (i < 16) {
                    word_index = (i & 15);
                    f = c ^ (a & (b ^ c));
                } else if (i < 32) {
                    word_index = ((1 + 5 * i) & 15);
                    f = (c & a) | (~c & b);
                } else if (i < 48) {
                    word_index = ((5 + 3 * i) & 15);
                    f = a ^ b ^ c;
                } else {
                    word_index = ((7 * i) & 15);
                    f = b ^ (a | ~c);
                }
                d += f + (((const union unaligned_32 *)(X + word_index))->l);
                d = a + (d << t | d >> (32 - t));
            } else if (i % 4 == 2) {
                c += T[i];
                uint32_t word_index, f;
                if (i < 16) {
                    word_index = (i & 15);
                    f = b ^ (d & (a ^ b));
                } else if (i < 32) {
                    word_index = ((1 + 5 * i) & 15);
                    f = (b & d) | (~b & a);
                } else if (i < 48) {
                    word_index = ((5 + 3 * i) & 15);
                    f = d ^ a ^ b;
                } else {
                    word_index = ((7 * i) & 15);
                    f = a ^ (d | ~b);
                }
                c += f + (((const union unaligned_32 *)(X + word_index))->l);
                c = d + (c << t | c >> (32 - t));
            } else {
                b += T[i];
                uint32_t word_index, f;
                if (i < 16) {
                    word_index = (i & 15);
                    f = a ^ (c & (d ^ a));
                } else if (i < 32) {
                    word_index = ((1 + 5 * i) & 15);
                    f = (a & c) | (~a & d);
                } else if (i < 48) {
                    word_index = ((5 + 3 * i) & 15);
                    f = c ^ d ^ a;
                } else {
                    word_index = ((7 * i) & 15);
                    f = d ^ (c | ~a);
                }
                b += f + (((const union unaligned_32 *)(X + word_index))->l);
                b = c + (b << t | b >> (32 - t));
            }
        }

        ABCD[0] += d;
        ABCD[1] += c;
        ABCD[2] += b;
        ABCD[3] += a;
    }
}
