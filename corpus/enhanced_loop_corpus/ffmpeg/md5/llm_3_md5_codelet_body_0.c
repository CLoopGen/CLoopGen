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

        // Change memory access to use a fully unrolled, consecutive layout with local caching of X values
        // Preload all required X values into a local array to enable coalesced, sequential access
        uint32_t X_local[16];
        const union unaligned_32 *ux = (const union unaligned_32 *)X;
        for (int i = 0; i < 16; i++) {
            X_local[i] = ux[i].l;
        }

        // Define function-like macros for clarity
        #define ROUND(a, b, c, d, k, f, shift)                    \
            a += T[k];                                            \
            a += f + X_local[(k < 16 ? (k & 15) :                  \
                            k < 32 ? ((1 + 5 * k) & 15) :         \
                            k < 48 ? ((5 + 3 * k) & 15) :         \
                                     ((7 * k) & 15))];           \
            a = b + (a << shift | a >> (32 - shift));

        // Repeated macro application mimicking original round structure
        ROUND(a, b, c, d, 0,  d ^ (b & (c ^ d)),          S[0][0]);
        ROUND(d, a, b, c, 1,  c ^ (a & (b ^ c)),          S[0][1]);
        ROUND(c, d, a, b, 2,  b ^ (d & (a ^ b)),          S[0][2]);
        ROUND(b, c, d, a, 3,  a ^ (c & (d ^ a)),          S[0][3]);
        ROUND(a, b, c, d, 4,  d ^ (b & (c ^ d)),          S[1][0]);
        ROUND(d, a, b, c, 5,  c ^ (a & (b ^ c)),          S[1][1]);
        ROUND(c, d, a, b, 6,  b ^ (d & (a ^ b)),          S[1][2]);
        ROUND(b, c, d, a, 7,  a ^ (c & (d ^ a)),          S[1][3]);
        ROUND(a, b, c, d, 8,  (d & b) | (~d & c),         S[2][0]);
        ROUND(d, a, b, c, 9,  (c & a) | (~c & b),         S[2][1]);
        ROUND(c, d, a, b, 10, (b & d) | (~b & a),         S[2][2]);
        ROUND(b, c, d, a, 11, (a & c) | (~a & d),         S[2][3]);
        ROUND(a, b, c, d, 12, (d & b) | (~d & c),         S[3][0]);
        ROUND(d, a, b, c, 13, (c & a) | (~c & b),         S[3][1]);
        ROUND(c, d, a, b, 14, (b & d) | (~b & a),         S[3][2]);
        ROUND(b, c, d, a, 15, (a & c) | (~a & d),         S[3][3]);

        ROUND(a, b, c, d, 16, (d & b) | (~d & c),        S[4][0]);
        ROUND(d, a, b, c, 17, (c & a) | (~c & b),        S[4][1]);
        ROUND(c, d, a, b, 18, (b & d) | (~b & a),        S[4][2]);
        ROUND(b, c, d, a, 19, (a & c) | (~a & d),        S[4][3]);
        ROUND(a, b, c, d, 20, (d & b) | (~d & c),        S[5][0]);
        ROUND(d, a, b, c, 21, (c & a) | (~c & b),        S[5][1]);
        ROUND(c, d, a, b, 22, (b & d) | (~b & a),        S[5][2]);
        ROUND(b, c, d, a, 23, (a & c) | (~a & d),        S[5][3]);
        ROUND(a, b, c, d, 24, (b ^ c ^ d),               S[6][0]);
        ROUND(d, a, b, c, 25, (a ^ b ^ c),               S[6][1]);
        ROUND(c, d, a, b, 26, (d ^ a ^ b),               S[6][2]);
        ROUND(b, c, d, a, 27, (c ^ d ^ a),               S[6][3]);
        ROUND(a, b, c, d, 28, (b ^ c ^ d),               S[7][0]);
        ROUND(d, a, b, c, 29, (a ^ b ^ c),               S[7][1]);
        ROUND(c, d, a, b, 30, (d ^ a ^ b),               S[7][2]);
        ROUND(b, c, d, a, 31, (c ^ d ^ a),               S[7][3]);

        ROUND(a, b, c, d, 32, (b ^ c ^ d),               S[8][0]);
        ROUND(d, a, b, c, 33, (a ^ b ^ c),               S[8][1]);
        ROUND(c, d, a, b, 34, (d ^ a ^ b),               S[8][2]);
        ROUND(b, c, d, a, 35, (c ^ d ^ a),               S[8][3]);
        ROUND(a, b, c, d, 36, (b ^ c ^ d),               S[9][0]);
        ROUND(d, a, b, c, 37, (a ^ b ^ c),               S[9][1]);
        ROUND(c, d, a, b, 38, (d ^ a ^ b),               S[9][2]);
        ROUND(b, c, d, a, 39, (c ^ d ^ a),               S[9][3]);
        ROUND(a, b, c, d, 40, (c ^ (b | ~d)),            S[10][0]);
        ROUND(d, a, b, c, 41, (b ^ (a | ~c)),            S[10][1]);
        ROUND(c, d, a, b, 42, (a ^ (d | ~b)),            S[10][2]);
        ROUND(b, c, d, a, 43, (d ^ (c | ~a)),            S[10][3]);
        ROUND(a, b, c, d, 44, (c ^ (b | ~d)),            S[11][0]);
        ROUND(d, a, b, c, 45, (b ^ (a | ~c)),            S[11][1]);
        ROUND(c, d, a, b, 46, (a ^ (d | ~b)),            S[11][2]);
        ROUND(b, c, d, a, 47, (d ^ (c | ~a)),            S[11][3]);

        ROUND(a, b, c, d, 48, (c ^ (b | ~d)),            S[12][0]);
        ROUND(d, a, b, c, 49, (b ^ (a | ~c)),            S[12][1]);
        ROUND(c, d, a, b, 50, (a ^ (d | ~b)),            S[12][2]);
        ROUND(b, c, d, a, 51, (d ^ (c | ~a)),            S[12][3]);
        ROUND(a, b, c, d, 52, (c ^ (b | ~d)),            S[13][0]);
        ROUND(d, a, b, c, 53, (b ^ (a | ~c)),            S[13][1]);
        ROUND(c, d, a, b, 54, (a ^ (d | ~b)),            S[13][2]);
        ROUND(b, c, d, a, 55, (d ^ (c | ~a)),            S[13][3]);
        ROUND(a, b, c, d, 56, (c ^ (b | ~d)),            S[14][0]);
        ROUND(d, a, b, c, 57, (b ^ (a | ~c)),            S[14][1]);
        ROUND(c, d, a, b, 58, (a ^ (d | ~b)),            S[14][2]);
        ROUND(b, c, d, a, 59, (d ^ (c | ~a)),            S[14][3]);
        ROUND(a, b, c, d, 60, (c ^ (b | ~d)),            S[15][0]);
        ROUND(d, a, b, c, 61, (b ^ (a | ~c)),            S[15][1]);
        ROUND(c, d, a, b, 62, (a ^ (d | ~b)),            S[15][2]);
        ROUND(b, c, d, a, 63, (d ^ (c | ~a)),            S[15][3]);

        #undef ROUND

        ABCD[0] += d;
        ABCD[1] += c;
        ABCD[2] += b;
        ABCD[3] += a;
    }
}
