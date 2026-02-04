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
    for (int i = 0; i < 64; i += 4) {
        t = S[i >> 4][i & 3];
        a += T[i];
        if (i < 32) {
            if (i < 16)
                a += (d ^ (b & (c ^ d))) + (((const union unaligned_32 *)(X + (i & 15)))->l);
            else
                a += ((d & b) | (~d & c)) + (((const union unaligned_32 *)(X + ((1 + 5 * i) & 15)))->l);
        } else {
            if (i < 48)
                a += (b ^ c ^ d) + (((const union unaligned_32 *)(X + ((5 + 3 * i) & 15)))->l);
            else
                a += (c ^ (b | ~d)) + (((const union unaligned_32 *)(X + ((7 * i) & 15)))->l);
        }
        a = b + (a << t | a >> (32 - t));

        t = S[(i + 1) >> 4][(i + 1) & 3];
        d += T[i + 1];
        if ((i + 1) < 32) {
            if ((i + 1) < 16)
                d += (c ^ (a & (b ^ c))) + (((const union unaligned_32 *)(X + ((i + 1) & 15)))->l);
            else
                d += ((c & a) | (~c & b)) + (((const union unaligned_32 *)(X + ((1 + 5 * (i + 1)) & 15)))->l);
        } else {
            if ((i + 1) < 48)
                d += (a ^ b ^ c) + (((const union unaligned_32 *)(X + ((5 + 3 * (i + 1)) & 15)))->l);
            else
                d += (b ^ (a | ~c)) + (((const union unaligned_32 *)(X + ((7 * (i + 1)) & 15)))->l);
        }
        d = a + (d << t | d >> (32 - t));

        t = S[(i + 2) >> 4][(i + 2) & 3];
        c += T[i + 2];
        if ((i + 2) < 32) {
            if ((i + 2) < 16)
                c += (b ^ (d & (a ^ b))) + (((const union unaligned_32 *)(X + ((i + 2) & 15)))->l);
            else
                c += ((b & d) | (~b & a)) + (((const union unaligned_32 *)(X + ((1 + 5 * (i + 2)) & 15)))->l);
        } else {
            if ((i + 2) < 48)
                c += (d ^ a ^ b) + (((const union unaligned_32 *)(X + ((5 + 3 * (i + 2)) & 15)))->l);
            else
                c += (a ^ (d | ~b)) + (((const union unaligned_32 *)(X + ((7 * (i + 2)) & 15)))->l);
        }
        c = d + (c << t | c >> (32 - t));

        t = S[(i + 3) >> 4][(i + 3) & 3];
        b += T[i + 3];
        if ((i + 3) < 32) {
            if ((i + 3) < 16)
                b += (a ^ (c & (d ^ a))) + (((const union unaligned_32 *)(X + ((i + 3) & 15)))->l);
            else
                b += ((a & c) | (~a & d)) + (((const union unaligned_32 *)(X + ((1 + 5 * (i + 3)) & 15)))->l);
        } else {
            if ((i + 3) < 48)
                b += (c ^ d ^ a) + (((const union unaligned_32 *)(X + ((5 + 3 * (i + 3)) & 15)))->l);
            else
                b += (d ^ (c | ~a)) + (((const union unaligned_32 *)(X + ((7 * (i + 3)) & 15)))->l);
        }
        b = c + (b << t | b >> (32 - t));
    }
    ABCD[0] += d;
    ABCD[1] += c;
    ABCD[2] += b;
    ABCD[3] += a;
}
}
