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
    do {
        t = S[0 >> 4][0 & 3];
        a += T[0];
        if (0 < 32) {
            if (0 < 16)
                a += (d ^ (b & (c ^ d))) + (((const union unaligned_32 *)(X + (0 & 15)))->l);
            else
                a += ((d & b) | (~d & c)) + (((const union unaligned_32 *)(X + ((1 + 5 * 0) & 15)))->l);
        } else {
            if (0 < 48)
                a += (b ^ c ^ d) + (((const union unaligned_32 *)(X + ((5 + 3 * 0) & 15)))->l);
            else
                a += (c ^ (b | ~d)) + (((const union unaligned_32 *)(X + ((7 * 0) & 15)))->l);
        }
        a = b + (a << t | a >> (32 - t));
    } while (0);
    do {
        t = S[(0 + 1) >> 4][(0 + 1) & 3];
        d += T[(0 + 1)];
        if ((0 + 1) < 32) {
            if ((0 + 1) < 16)
                d += (c ^ (a & (b ^ c))) + (((const union unaligned_32 *)(X + ((0 + 1) & 15)))->l);
            else
                d += ((c & a) | (~c & b)) + (((const union unaligned_32 *)(X + ((1 + 5 * (0 + 1)) & 15)))->l);
        } else {
            if ((0 + 1) < 48)
                d += (a ^ b ^ c) + (((const union unaligned_32 *)(X + ((5 + 3 * (0 + 1)) & 15)))->l);
            else
                d += (b ^ (a | ~c)) + (((const union unaligned_32 *)(X + ((7 * (0 + 1)) & 15)))->l);
        }
        d = a + (d << t | d >> (32 - t));
    } while (0);
    do {
        t = S[(0 + 2) >> 4][(0 + 2) & 3];
        c += T[(0 + 2)];
        if ((0 + 2) < 32) {
            if ((0 + 2) < 16)
                c += (b ^ (d & (a ^ b))) + (((const union unaligned_32 *)(X + ((0 + 2) & 15)))->l);
            else
                c += ((b & d) | (~b & a)) + (((const union unaligned_32 *)(X + ((1 + 5 * (0 + 2)) & 15)))->l);
        } else {
            if ((0 + 2) < 48)
                c += (d ^ a ^ b) + (((const union unaligned_32 *)(X + ((5 + 3 * (0 + 2)) & 15)))->l);
            else
                c += (a ^ (d | ~b)) + (((const union unaligned_32 *)(X + ((7 * (0 + 2)) & 15)))->l);
        }
        c = d + (c << t | c >> (32 - t));
    } while (0);
    do {
        t = S[(0 + 3) >> 4][(0 + 3) & 3];
        b += T[(0 + 3)];
        if ((0 + 3) < 32) {
            if ((0 + 3) < 16)
                b += (a ^ (c & (d ^ a))) + (((const union unaligned_32 *)(X + ((0 + 3) & 15)))->l);
            else
                b += ((a & c) | (~a & d)) + (((const union unaligned_32 *)(X + ((1 + 5 * (0 + 3)) & 15)))->l);
        } else {
            if ((0 + 3) < 48)
                b += (c ^ d ^ a) + (((const union unaligned_32 *)(X + ((5 + 3 * (0 + 3)) & 15)))->l);
            else
                b += (d ^ (c | ~a)) + (((const union unaligned_32 *)(X + ((7 * (0 + 3)) & 15)))->l);
        }
        b = c + (b << t | b >> (32 - t));
    } while (0);
    do {
        t = S[(0 + 4) >> 4][(0 + 4) & 3];
        a += T[(0 + 4)];
        if ((0 + 4) < 32) {
            if ((0 + 4) < 16)
                a += (d ^ (b & (c ^ d))) + (((const union unaligned_32 *)(X + ((0 + 4) & 15)))->l);
            else
                a += ((d & b) | (~d & c)) + (((const union unaligned_32 *)(X + ((1 + 5 * (0 + 4)) & 15)))->l);
        } else {
            if ((0 + 4) < 48)
                a += (b ^ c ^ d) + (((const union unaligned_32 *)(X + ((5 + 3 * (0 + 4)) & 15)))->l);
            else
                a += (c ^ (b | ~d)) + (((const union unaligned_32 *)(X + ((7 * (0 + 4)) & 15)))->l);
        }
        a = b + (a << t | a >> (32 - t));
    } while (0);
    do {
        t = S[((0 + 4) + 1) >> 4][((0 + 4) + 1) & 3];
        d += T[((0 + 4) + 1)];
        if (((0 + 4) + 1) < 32) {
            if (((0 + 4) + 1) < 16)
                d += (c ^ (a & (b ^ c))) + (((const union unaligned_32 *)(X + (((0 + 4) + 1) & 15)))->l);
            else
                d += ((c & a) | (~c & b)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((0 + 4) + 1)) & 15)))->l);
        } else {
            if (((0 + 4) + 1) < 48)
                d += (a ^ b ^ c) + (((const union unaligned_32 *)(X + ((5 + 3 * ((0 + 4) + 1)) & 15)))->l);
            else
                d += (b ^ (a | ~c)) + (((const union unaligned_32 *)(X + ((7 * ((0 + 4) + 1)) & 15)))->l);
        }
        d = a + (d << t | d >> (32 - t));
    } while (0);
    do {
        t = S[((0 + 4) + 2) >> 4][((0 + 4) + 2) & 3];
        c += T[((0 + 4) + 2)];
        if (((0 + 4) + 2) < 32) {
            if (((0 + 4) + 2) < 16)
                c += (b ^ (d & (a ^ b))) + (((const union unaligned_32 *)(X + (((0 + 4) + 2) & 15)))->l);
            else
                c += ((b & d) | (~b & a)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((0 + 4) + 2)) & 15)))->l);
        } else {
            if (((0 + 4) + 2) < 48)
                c += (d ^ a ^ b) + (((const union unaligned_32 *)(X + ((5 + 3 * ((0 + 4) + 2)) & 15)))->l);
            else
                c += (a ^ (d | ~b)) + (((const union unaligned_32 *)(X + ((7 * ((0 + 4) + 2)) & 15)))->l);
        }
        c = d + (c << t | c >> (32 - t));
    } while (0);
    do {
        t = S[((0 + 4) + 3) >> 4][((0 + 4) + 3) & 3];
        b += T[((0 + 4) + 3)];
        if (((0 + 4) + 3) < 32) {
            if (((0 + 4) + 3) < 16)
                b += (a ^ (c & (d ^ a))) + (((const union unaligned_32 *)(X + (((0 + 4) + 3) & 15)))->l);
            else
                b += ((a & c) | (~a & d)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((0 + 4) + 3)) & 15)))->l);
        } else {
            if (((0 + 4) + 3) < 48)
                b += (c ^ d ^ a) + (((const union unaligned_32 *)(X + ((5 + 3 * ((0 + 4) + 3)) & 15)))->l);
            else
                b += (d ^ (c | ~a)) + (((const union unaligned_32 *)(X + ((7 * ((0 + 4) + 3)) & 15)))->l);
        }
        b = c + (b << t | b >> (32 - t));
    } while (0);
    do {
        t = S[(0 + 8) >> 4][(0 + 8) & 3];
        a += T[(0 + 8)];
        if ((0 + 8) < 32) {
            if ((0 + 8) < 16)
                a += (d ^ (b & (c ^ d))) + (((const union unaligned_32 *)(X + ((0 + 8) & 15)))->l);
            else
                a += ((d & b) | (~d & c)) + (((const union unaligned_32 *)(X + ((1 + 5 * (0 + 8)) & 15)))->l);
        } else {
            if ((0 + 8) < 48)
                a += (b ^ c ^ d) + (((const union unaligned_32 *)(X + ((5 + 3 * (0 + 8)) & 15)))->l);
            else
                a += (c ^ (b | ~d)) + (((const union unaligned_32 *)(X + ((7 * (0 + 8)) & 15)))->l);
        }
        a = b + (a << t | a >> (32 - t));
    } while (0);
    do {
        t = S[((0 + 8) + 1) >> 4][((0 + 8) + 1) & 3];
        d += T[((0 + 8) + 1)];
        if (((0 + 8) + 1) < 32) {
            if (((0 + 8) + 1) < 16)
                d += (c ^ (a & (b ^ c))) + (((const union unaligned_32 *)(X + (((0 + 8) + 1) & 15)))->l);
            else
                d += ((c & a) | (~c & b)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((0 + 8) + 1)) & 15)))->l);
        } else {
            if (((0 + 8) + 1) < 48)
                d += (a ^ b ^ c) + (((const union unaligned_32 *)(X + ((5 + 3 * ((0 + 8) + 1)) & 15)))->l);
            else
                d += (b ^ (a | ~c)) + (((const union unaligned_32 *)(X + ((7 * ((0 + 8) + 1)) & 15)))->l);
        }
        d = a + (d << t | d >> (32 - t));
    } while (0);
    do {
        t = S[((0 + 8) + 2) >> 4][((0 + 8) + 2) & 3];
        c += T[((0 + 8) + 2)];
        if (((0 + 8) + 2) < 32) {
            if (((0 + 8) + 2) < 16)
                c += (b ^ (d & (a ^ b))) + (((const union unaligned_32 *)(X + (((0 + 8) + 2) & 15)))->l);
            else
                c += ((b & d) | (~b & a)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((0 + 8) + 2)) & 15)))->l);
        } else {
            if (((0 + 8) + 2) < 48)
                c += (d ^ a ^ b) + (((const union unaligned_32 *)(X + ((5 + 3 * ((0 + 8) + 2)) & 15)))->l);
            else
                c += (a ^ (d | ~b)) + (((const union unaligned_32 *)(X + ((7 * ((0 + 8) + 2)) & 15)))->l);
        }
        c = d + (c << t | c >> (32 - t));
    } while (0);
    do {
        t = S[((0 + 8) + 3) >> 4][((0 + 8) + 3) & 3];
        b += T[((0 + 8) + 3)];
        if (((0 + 8) + 3) < 32) {
            if (((0 + 8) + 3) < 16)
                b += (a ^ (c & (d ^ a))) + (((const union unaligned_32 *)(X + (((0 + 8) + 3) & 15)))->l);
            else
                b += ((a & c) | (~a & d)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((0 + 8) + 3)) & 15)))->l);
        } else {
            if (((0 + 8) + 3) < 48)
                b += (c ^ d ^ a) + (((const union unaligned_32 *)(X + ((5 + 3 * ((0 + 8) + 3)) & 15)))->l);
            else
                b += (d ^ (c | ~a)) + (((const union unaligned_32 *)(X + ((7 * ((0 + 8) + 3)) & 15)))->l);
        }
        b = c + (b << t | b >> (32 - t));
    } while (0);
    do {
        t = S[(0 + 12) >> 4][(0 + 12) & 3];
        a += T[(0 + 12)];
        if ((0 + 12) < 32) {
            if ((0 + 12) < 16)
                a += (d ^ (b & (c ^ d))) + (((const union unaligned_32 *)(X + ((0 + 12) & 15)))->l);
            else
                a += ((d & b) | (~d & c)) + (((const union unaligned_32 *)(X + ((1 + 5 * (0 + 12)) & 15)))->l);
        } else {
            if ((0 + 12) < 48)
                a += (b ^ c ^ d) + (((const union unaligned_32 *)(X + ((5 + 3 * (0 + 12)) & 15)))->l);
            else
                a += (c ^ (b | ~d)) + (((const union unaligned_32 *)(X + ((7 * (0 + 12)) & 15)))->l);
        }
        a = b + (a << t | a >> (32 - t));
    } while (0);
    do {
        t = S[((0 + 12) + 1) >> 4][((0 + 12) + 1) & 3];
        d += T[((0 + 12) + 1)];
        if (((0 + 12) + 1) < 32) {
            if (((0 + 12) + 1) < 16)
                d += (c ^ (a & (b ^ c))) + (((const union unaligned_32 *)(X + (((0 + 12) + 1) & 15)))->l);
            else
                d += ((c & a) | (~c & b)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((0 + 12) + 1)) & 15)))->l);
        } else {
            if (((0 + 12) + 1) < 48)
                d += (a ^ b ^ c) + (((const union unaligned_32 *)(X + ((5 + 3 * ((0 + 12) + 1)) & 15)))->l);
            else
                d += (b ^ (a | ~c)) + (((const union unaligned_32 *)(X + ((7 * ((0 + 12) + 1)) & 15)))->l);
        }
        d = a + (d << t | d >> (32 - t));
    } while (0);
    do {
        t = S[((0 + 12) + 2) >> 4][((0 + 12) + 2) & 3];
        c += T[((0 + 12) + 2)];
        if (((0 + 12) + 2) < 32) {
            if (((0 + 12) + 2) < 16)
                c += (b ^ (d & (a ^ b))) + (((const union unaligned_32 *)(X + (((0 + 12) + 2) & 15)))->l);
            else
                c += ((b & d) | (~b & a)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((0 + 12) + 2)) & 15)))->l);
        } else {
            if (((0 + 12) + 2) < 48)
                c += (d ^ a ^ b) + (((const union unaligned_32 *)(X + ((5 + 3 * ((0 + 12) + 2)) & 15)))->l);
            else
                c += (a ^ (d | ~b)) + (((const union unaligned_32 *)(X + ((7 * ((0 + 12) + 2)) & 15)))->l);
        }
        c = d + (c << t | c >> (32 - t));
    } while (0);
    do {
        t = S[((0 + 12) + 3) >> 4][((0 + 12) + 3) & 3];
        b += T[((0 + 12) + 3)];
        if (((0 + 12) + 3) < 32) {
            if (((0 + 12) + 3) < 16)
                b += (a ^ (c & (d ^ a))) + (((const union unaligned_32 *)(X + (((0 + 12) + 3) & 15)))->l);
            else
                b += ((a & c) | (~a & d)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((0 + 12) + 3)) & 15)))->l);
        } else {
            if (((0 + 12) + 3) < 48)
                b += (c ^ d ^ a) + (((const union unaligned_32 *)(X + ((5 + 3 * ((0 + 12) + 3)) & 15)))->l);
            else
                b += (d ^ (c | ~a)) + (((const union unaligned_32 *)(X + ((7 * ((0 + 12) + 3)) & 15)))->l);
        }
        b = c + (b << t | b >> (32 - t));
    } while (0);
    do {
        t = S[16 >> 4][16 & 3];
        a += T[16];
        if (16 < 32) {
            if (16 < 16)
                a += (d ^ (b & (c ^ d))) + (((const union unaligned_32 *)(X + (16 & 15)))->l);
            else
                a += ((d & b) | (~d & c)) + (((const union unaligned_32 *)(X + ((1 + 5 * 16) & 15)))->l);
        } else {
            if (16 < 48)
                a += (b ^ c ^ d) + (((const union unaligned_32 *)(X + ((5 + 3 * 16) & 15)))->l);
            else
                a += (c ^ (b | ~d)) + (((const union unaligned_32 *)(X + ((7 * 16) & 15)))->l);
        }
        a = b + (a << t | a >> (32 - t));
    } while (0);
    do {
        t = S[(16 + 1) >> 4][(16 + 1) & 3];
        d += T[(16 + 1)];
        if ((16 + 1) < 32) {
            if ((16 + 1) < 16)
                d += (c ^ (a & (b ^ c))) + (((const union unaligned_32 *)(X + ((16 + 1) & 15)))->l);
            else
                d += ((c & a) | (~c & b)) + (((const union unaligned_32 *)(X + ((1 + 5 * (16 + 1)) & 15)))->l);
        } else {
            if ((16 + 1) < 48)
                d += (a ^ b ^ c) + (((const union unaligned_32 *)(X + ((5 + 3 * (16 + 1)) & 15)))->l);
            else
                d += (b ^ (a | ~c)) + (((const union unaligned_32 *)(X + ((7 * (16 + 1)) & 15)))->l);
        }
        d = a + (d << t | d >> (32 - t));
    } while (0);
    do {
        t = S[(16 + 2) >> 4][(16 + 2) & 3];
        c += T[(16 + 2)];
        if ((16 + 2) < 32) {
            if ((16 + 2) < 16)
                c += (b ^ (d & (a ^ b))) + (((const union unaligned_32 *)(X + ((16 + 2) & 15)))->l);
            else
                c += ((b & d) | (~b & a)) + (((const union unaligned_32 *)(X + ((1 + 5 * (16 + 2)) & 15)))->l);
        } else {
            if ((16 + 2) < 48)
                c += (d ^ a ^ b) + (((const union unaligned_32 *)(X + ((5 + 3 * (16 + 2)) & 15)))->l);
            else
                c += (a ^ (d | ~b)) + (((const union unaligned_32 *)(X + ((7 * (16 + 2)) & 15)))->l);
        }
        c = d + (c << t | c >> (32 - t));
    } while (0);
    do {
        t = S[(16 + 3) >> 4][(16 + 3) & 3];
        b += T[(16 + 3)];
        if ((16 + 3) < 32) {
            if ((16 + 3) < 16)
                b += (a ^ (c & (d ^ a))) + (((const union unaligned_32 *)(X + ((16 + 3) & 15)))->l);
            else
                b += ((a & c) | (~a & d)) + (((const union unaligned_32 *)(X + ((1 + 5 * (16 + 3)) & 15)))->l);
        } else {
            if ((16 + 3) < 48)
                b += (c ^ d ^ a) + (((const union unaligned_32 *)(X + ((5 + 3 * (16 + 3)) & 15)))->l);
            else
                b += (d ^ (c | ~a)) + (((const union unaligned_32 *)(X + ((7 * (16 + 3)) & 15)))->l);
        }
        b = c + (b << t | b >> (32 - t));
    } while (0);
    do {
        t = S[(16 + 4) >> 4][(16 + 4) & 3];
        a += T[(16 + 4)];
        if ((16 + 4) < 32) {
            if ((16 + 4) < 16)
                a += (d ^ (b & (c ^ d))) + (((const union unaligned_32 *)(X + ((16 + 4) & 15)))->l);
            else
                a += ((d & b) | (~d & c)) + (((const union unaligned_32 *)(X + ((1 + 5 * (16 + 4)) & 15)))->l);
        } else {
            if ((16 + 4) < 48)
                a += (b ^ c ^ d) + (((const union unaligned_32 *)(X + ((5 + 3 * (16 + 4)) & 15)))->l);
            else
                a += (c ^ (b | ~d)) + (((const union unaligned_32 *)(X + ((7 * (16 + 4)) & 15)))->l);
        }
        a = b + (a << t | a >> (32 - t));
    } while (0);
    do {
        t = S[((16 + 4) + 1) >> 4][((16 + 4) + 1) & 3];
        d += T[((16 + 4) + 1)];
        if (((16 + 4) + 1) < 32) {
            if (((16 + 4) + 1) < 16)
                d += (c ^ (a & (b ^ c))) + (((const union unaligned_32 *)(X + (((16 + 4) + 1) & 15)))->l);
            else
                d += ((c & a) | (~c & b)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((16 + 4) + 1)) & 15)))->l);
        } else {
            if (((16 + 4) + 1) < 48)
                d += (a ^ b ^ c) + (((const union unaligned_32 *)(X + ((5 + 3 * ((16 + 4) + 1)) & 15)))->l);
            else
                d += (b ^ (a | ~c)) + (((const union unaligned_32 *)(X + ((7 * ((16 + 4) + 1)) & 15)))->l);
        }
        d = a + (d << t | d >> (32 - t));
    } while (0);
    do {
        t = S[((16 + 4) + 2) >> 4][((16 + 4) + 2) & 3];
        c += T[((16 + 4) + 2)];
        if (((16 + 4) + 2) < 32) {
            if (((16 + 4) + 2) < 16)
                c += (b ^ (d & (a ^ b))) + (((const union unaligned_32 *)(X + (((16 + 4) + 2) & 15)))->l);
            else
                c += ((b & d) | (~b & a)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((16 + 4) + 2)) & 15)))->l);
        } else {
            if (((16 + 4) + 2) < 48)
                c += (d ^ a ^ b) + (((const union unaligned_32 *)(X + ((5 + 3 * ((16 + 4) + 2)) & 15)))->l);
            else
                c += (a ^ (d | ~b)) + (((const union unaligned_32 *)(X + ((7 * ((16 + 4) + 2)) & 15)))->l);
        }
        c = d + (c << t | c >> (32 - t));
    } while (0);
    do {
        t = S[((16 + 4) + 3) >> 4][((16 + 4) + 3) & 3];
        b += T[((16 + 4) + 3)];
        if (((16 + 4) + 3) < 32) {
            if (((16 + 4) + 3) < 16)
                b += (a ^ (c & (d ^ a))) + (((const union unaligned_32 *)(X + (((16 + 4) + 3) & 15)))->l);
            else
                b += ((a & c) | (~a & d)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((16 + 4) + 3)) & 15)))->l);
        } else {
            if (((16 + 4) + 3) < 48)
                b += (c ^ d ^ a) + (((const union unaligned_32 *)(X + ((5 + 3 * ((16 + 4) + 3)) & 15)))->l);
            else
                b += (d ^ (c | ~a)) + (((const union unaligned_32 *)(X + ((7 * ((16 + 4) + 3)) & 15)))->l);
        }
        b = c + (b << t | b >> (32 - t));
    } while (0);
    do {
        t = S[(16 + 8) >> 4][(16 + 8) & 3];
        a += T[(16 + 8)];
        if ((16 + 8) < 32) {
            if ((16 + 8) < 16)
                a += (d ^ (b & (c ^ d))) + (((const union unaligned_32 *)(X + ((16 + 8) & 15)))->l);
            else
                a += ((d & b) | (~d & c)) + (((const union unaligned_32 *)(X + ((1 + 5 * (16 + 8)) & 15)))->l);
        } else {
            if ((16 + 8) < 48)
                a += (b ^ c ^ d) + (((const union unaligned_32 *)(X + ((5 + 3 * (16 + 8)) & 15)))->l);
            else
                a += (c ^ (b | ~d)) + (((const union unaligned_32 *)(X + ((7 * (16 + 8)) & 15)))->l);
        }
        a = b + (a << t | a >> (32 - t));
    } while (0);
    do {
        t = S[((16 + 8) + 1) >> 4][((16 + 8) + 1) & 3];
        d += T[((16 + 8) + 1)];
        if (((16 + 8) + 1) < 32) {
            if (((16 + 8) + 1) < 16)
                d += (c ^ (a & (b ^ c))) + (((const union unaligned_32 *)(X + (((16 + 8) + 1) & 15)))->l);
            else
                d += ((c & a) | (~c & b)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((16 + 8) + 1)) & 15)))->l);
        } else {
            if (((16 + 8) + 1) < 48)
                d += (a ^ b ^ c) + (((const union unaligned_32 *)(X + ((5 + 3 * ((16 + 8) + 1)) & 15)))->l);
            else
                d += (b ^ (a | ~c)) + (((const union unaligned_32 *)(X + ((7 * ((16 + 8) + 1)) & 15)))->l);
        }
        d = a + (d << t | d >> (32 - t));
    } while (0);
    do {
        t = S[((16 + 8) + 2) >> 4][((16 + 8) + 2) & 3];
        c += T[((16 + 8) + 2)];
        if (((16 + 8) + 2) < 32) {
            if (((16 + 8) + 2) < 16)
                c += (b ^ (d & (a ^ b))) + (((const union unaligned_32 *)(X + (((16 + 8) + 2) & 15)))->l);
            else
                c += ((b & d) | (~b & a)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((16 + 8) + 2)) & 15)))->l);
        } else {
            if (((16 + 8) + 2) < 48)
                c += (d ^ a ^ b) + (((const union unaligned_32 *)(X + ((5 + 3 * ((16 + 8) + 2)) & 15)))->l);
            else
                c += (a ^ (d | ~b)) + (((const union unaligned_32 *)(X + ((7 * ((16 + 8) + 2)) & 15)))->l);
        }
        c = d + (c << t | c >> (32 - t));
    } while (0);
    do {
        t = S[((16 + 8) + 3) >> 4][((16 + 8) + 3) & 3];
        b += T[((16 + 8) + 3)];
        if (((16 + 8) + 3) < 32) {
            if (((16 + 8) + 3) < 16)
                b += (a ^ (c & (d ^ a))) + (((const union unaligned_32 *)(X + (((16 + 8) + 3) & 15)))->l);
            else
                b += ((a & c) | (~a & d)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((16 + 8) + 3)) & 15)))->l);
        } else {
            if (((16 + 8) + 3) < 48)
                b += (c ^ d ^ a) + (((const union unaligned_32 *)(X + ((5 + 3 * ((16 + 8) + 3)) & 15)))->l);
            else
                b += (d ^ (c | ~a)) + (((const union unaligned_32 *)(X + ((7 * ((16 + 8) + 3)) & 15)))->l);
        }
        b = c + (b << t | b >> (32 - t));
    } while (0);
    do {
        t = S[(16 + 12) >> 4][(16 + 12) & 3];
        a += T[(16 + 12)];
        if ((16 + 12) < 32) {
            if ((16 + 12) < 16)
                a += (d ^ (b & (c ^ d))) + (((const union unaligned_32 *)(X + ((16 + 12) & 15)))->l);
            else
                a += ((d & b) | (~d & c)) + (((const union unaligned_32 *)(X + ((1 + 5 * (16 + 12)) & 15)))->l);
        } else {
            if ((16 + 12) < 48)
                a += (b ^ c ^ d) + (((const union unaligned_32 *)(X + ((5 + 3 * (16 + 12)) & 15)))->l);
            else
                a += (c ^ (b | ~d)) + (((const union unaligned_32 *)(X + ((7 * (16 + 12)) & 15)))->l);
        }
        a = b + (a << t | a >> (32 - t));
    } while (0);
    do {
        t = S[((16 + 12) + 1) >> 4][((16 + 12) + 1) & 3];
        d += T[((16 + 12) + 1)];
        if (((16 + 12) + 1) < 32) {
            if (((16 + 12) + 1) < 16)
                d += (c ^ (a & (b ^ c))) + (((const union unaligned_32 *)(X + (((16 + 12) + 1) & 15)))->l);
            else
                d += ((c & a) | (~c & b)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((16 + 12) + 1)) & 15)))->l);
        } else {
            if (((16 + 12) + 1) < 48)
                d += (a ^ b ^ c) + (((const union unaligned_32 *)(X + ((5 + 3 * ((16 + 12) + 1)) & 15)))->l);
            else
                d += (b ^ (a | ~c)) + (((const union unaligned_32 *)(X + ((7 * ((16 + 12) + 1)) & 15)))->l);
        }
        d = a + (d << t | d >> (32 - t));
    } while (0);
    do {
        t = S[((16 + 12) + 2) >> 4][((16 + 12) + 2) & 3];
        c += T[((16 + 12) + 2)];
        if (((16 + 12) + 2) < 32) {
            if (((16 + 12) + 2) < 16)
                c += (b ^ (d & (a ^ b))) + (((const union unaligned_32 *)(X + (((16 + 12) + 2) & 15)))->l);
            else
                c += ((b & d) | (~b & a)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((16 + 12) + 2)) & 15)))->l);
        } else {
            if (((16 + 12) + 2) < 48)
                c += (d ^ a ^ b) + (((const union unaligned_32 *)(X + ((5 + 3 * ((16 + 12) + 2)) & 15)))->l);
            else
                c += (a ^ (d | ~b)) + (((const union unaligned_32 *)(X + ((7 * ((16 + 12) + 2)) & 15)))->l);
        }
        c = d + (c << t | c >> (32 - t));
    } while (0);
    do {
        t = S[((16 + 12) + 3) >> 4][((16 + 12) + 3) & 3];
        b += T[((16 + 12) + 3)];
        if (((16 + 12) + 3) < 32) {
            if (((16 + 12) + 3) < 16)
                b += (a ^ (c & (d ^ a))) + (((const union unaligned_32 *)(X + (((16 + 12) + 3) & 15)))->l);
            else
                b += ((a & c) | (~a & d)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((16 + 12) + 3)) & 15)))->l);
        } else {
            if (((16 + 12) + 3) < 48)
                b += (c ^ d ^ a) + (((const union unaligned_32 *)(X + ((5 + 3 * ((16 + 12) + 3)) & 15)))->l);
            else
                b += (d ^ (c | ~a)) + (((const union unaligned_32 *)(X + ((7 * ((16 + 12) + 3)) & 15)))->l);
        }
        b = c + (b << t | b >> (32 - t));
    } while (0);
    do {
        t = S[32 >> 4][32 & 3];
        a += T[32];
        if (32 < 32) {
            if (32 < 16)
                a += (d ^ (b & (c ^ d))) + (((const union unaligned_32 *)(X + (32 & 15)))->l);
            else
                a += ((d & b) | (~d & c)) + (((const union unaligned_32 *)(X + ((1 + 5 * 32) & 15)))->l);
        } else {
            if (32 < 48)
                a += (b ^ c ^ d) + (((const union unaligned_32 *)(X + ((5 + 3 * 32) & 15)))->l);
            else
                a += (c ^ (b | ~d)) + (((const union unaligned_32 *)(X + ((7 * 32) & 15)))->l);
        }
        a = b + (a << t | a >> (32 - t));
    } while (0);
    do {
        t = S[(32 + 1) >> 4][(32 + 1) & 3];
        d += T[(32 + 1)];
        if ((32 + 1) < 32) {
            if ((32 + 1) < 16)
                d += (c ^ (a & (b ^ c))) + (((const union unaligned_32 *)(X + ((32 + 1) & 15)))->l);
            else
                d += ((c & a) | (~c & b)) + (((const union unaligned_32 *)(X + ((1 + 5 * (32 + 1)) & 15)))->l);
        } else {
            if ((32 + 1) < 48)
                d += (a ^ b ^ c) + (((const union unaligned_32 *)(X + ((5 + 3 * (32 + 1)) & 15)))->l);
            else
                d += (b ^ (a | ~c)) + (((const union unaligned_32 *)(X + ((7 * (32 + 1)) & 15)))->l);
        }
        d = a + (d << t | d >> (32 - t));
    } while (0);
    do {
        t = S[(32 + 2) >> 4][(32 + 2) & 3];
        c += T[(32 + 2)];
        if ((32 + 2) < 32) {
            if ((32 + 2) < 16)
                c += (b ^ (d & (a ^ b))) + (((const union unaligned_32 *)(X + ((32 + 2) & 15)))->l);
            else
                c += ((b & d) | (~b & a)) + (((const union unaligned_32 *)(X + ((1 + 5 * (32 + 2)) & 15)))->l);
        } else {
            if ((32 + 2) < 48)
                c += (d ^ a ^ b) + (((const union unaligned_32 *)(X + ((5 + 3 * (32 + 2)) & 15)))->l);
            else
                c += (a ^ (d | ~b)) + (((const union unaligned_32 *)(X + ((7 * (32 + 2)) & 15)))->l);
        }
        c = d + (c << t | c >> (32 - t));
    } while (0);
    do {
        t = S[(32 + 3) >> 4][(32 + 3) & 3];
        b += T[(32 + 3)];
        if ((32 + 3) < 32) {
            if ((32 + 3) < 16)
                b += (a ^ (c & (d ^ a))) + (((const union unaligned_32 *)(X + ((32 + 3) & 15)))->l);
            else
                b += ((a & c) | (~a & d)) + (((const union unaligned_32 *)(X + ((1 + 5 * (32 + 3)) & 15)))->l);
        } else {
            if ((32 + 3) < 48)
                b += (c ^ d ^ a) + (((const union unaligned_32 *)(X + ((5 + 3 * (32 + 3)) & 15)))->l);
            else
                b += (d ^ (c | ~a)) + (((const union unaligned_32 *)(X + ((7 * (32 + 3)) & 15)))->l);
        }
        b = c + (b << t | b >> (32 - t));
    } while (0);
    do {
        t = S[(32 + 4) >> 4][(32 + 4) & 3];
        a += T[(32 + 4)];
        if ((32 + 4) < 32) {
            if ((32 + 4) < 16)
                a += (d ^ (b & (c ^ d))) + (((const union unaligned_32 *)(X + ((32 + 4) & 15)))->l);
            else
                a += ((d & b) | (~d & c)) + (((const union unaligned_32 *)(X + ((1 + 5 * (32 + 4)) & 15)))->l);
        } else {
            if ((32 + 4) < 48)
                a += (b ^ c ^ d) + (((const union unaligned_32 *)(X + ((5 + 3 * (32 + 4)) & 15)))->l);
            else
                a += (c ^ (b | ~d)) + (((const union unaligned_32 *)(X + ((7 * (32 + 4)) & 15)))->l);
        }
        a = b + (a << t | a >> (32 - t));
    } while (0);
    do {
        t = S[((32 + 4) + 1) >> 4][((32 + 4) + 1) & 3];
        d += T[((32 + 4) + 1)];
        if (((32 + 4) + 1) < 32) {
            if (((32 + 4) + 1) < 16)
                d += (c ^ (a & (b ^ c))) + (((const union unaligned_32 *)(X + (((32 + 4) + 1) & 15)))->l);
            else
                d += ((c & a) | (~c & b)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((32 + 4) + 1)) & 15)))->l);
        } else {
            if (((32 + 4) + 1) < 48)
                d += (a ^ b ^ c) + (((const union unaligned_32 *)(X + ((5 + 3 * ((32 + 4) + 1)) & 15)))->l);
            else
                d += (b ^ (a | ~c)) + (((const union unaligned_32 *)(X + ((7 * ((32 + 4) + 1)) & 15)))->l);
        }
        d = a + (d << t | d >> (32 - t));
    } while (0);
    do {
        t = S[((32 + 4) + 2) >> 4][((32 + 4) + 2) & 3];
        c += T[((32 + 4) + 2)];
        if (((32 + 4) + 2) < 32) {
            if (((32 + 4) + 2) < 16)
                c += (b ^ (d & (a ^ b))) + (((const union unaligned_32 *)(X + (((32 + 4) + 2) & 15)))->l);
            else
                c += ((b & d) | (~b & a)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((32 + 4) + 2)) & 15)))->l);
        } else {
            if (((32 + 4) + 2) < 48)
                c += (d ^ a ^ b) + (((const union unaligned_32 *)(X + ((5 + 3 * ((32 + 4) + 2)) & 15)))->l);
            else
                c += (a ^ (d | ~b)) + (((const union unaligned_32 *)(X + ((7 * ((32 + 4) + 2)) & 15)))->l);
        }
        c = d + (c << t | c >> (32 - t));
    } while (0);
    do {
        t = S[((32 + 4) + 3) >> 4][((32 + 4) + 3) & 3];
        b += T[((32 + 4) + 3)];
        if (((32 + 4) + 3) < 32) {
            if (((32 + 4) + 3) < 16)
                b += (a ^ (c & (d ^ a))) + (((const union unaligned_32 *)(X + (((32 + 4) + 3) & 15)))->l);
            else
                b += ((a & c) | (~a & d)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((32 + 4) + 3)) & 15)))->l);
        } else {
            if (((32 + 4) + 3) < 48)
                b += (c ^ d ^ a) + (((const union unaligned_32 *)(X + ((5 + 3 * ((32 + 4) + 3)) & 15)))->l);
            else
                b += (d ^ (c | ~a)) + (((const union unaligned_32 *)(X + ((7 * ((32 + 4) + 3)) & 15)))->l);
        }
        b = c + (b << t | b >> (32 - t));
    } while (0);
    do {
        t = S[(32 + 8) >> 4][(32 + 8) & 3];
        a += T[(32 + 8)];
        if ((32 + 8) < 32) {
            if ((32 + 8) < 16)
                a += (d ^ (b & (c ^ d))) + (((const union unaligned_32 *)(X + ((32 + 8) & 15)))->l);
            else
                a += ((d & b) | (~d & c)) + (((const union unaligned_32 *)(X + ((1 + 5 * (32 + 8)) & 15)))->l);
        } else {
            if ((32 + 8) < 48)
                a += (b ^ c ^ d) + (((const union unaligned_32 *)(X + ((5 + 3 * (32 + 8)) & 15)))->l);
            else
                a += (c ^ (b | ~d)) + (((const union unaligned_32 *)(X + ((7 * (32 + 8)) & 15)))->l);
        }
        a = b + (a << t | a >> (32 - t));
    } while (0);
    do {
        t = S[((32 + 8) + 1) >> 4][((32 + 8) + 1) & 3];
        d += T[((32 + 8) + 1)];
        if (((32 + 8) + 1) < 32) {
            if (((32 + 8) + 1) < 16)
                d += (c ^ (a & (b ^ c))) + (((const union unaligned_32 *)(X + (((32 + 8) + 1) & 15)))->l);
            else
                d += ((c & a) | (~c & b)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((32 + 8) + 1)) & 15)))->l);
        } else {
            if (((32 + 8) + 1) < 48)
                d += (a ^ b ^ c) + (((const union unaligned_32 *)(X + ((5 + 3 * ((32 + 8) + 1)) & 15)))->l);
            else
                d += (b ^ (a | ~c)) + (((const union unaligned_32 *)(X + ((7 * ((32 + 8) + 1)) & 15)))->l);
        }
        d = a + (d << t | d >> (32 - t));
    } while (0);
    do {
        t = S[((32 + 8) + 2) >> 4][((32 + 8) + 2) & 3];
        c += T[((32 + 8) + 2)];
        if (((32 + 8) + 2) < 32) {
            if (((32 + 8) + 2) < 16)
                c += (b ^ (d & (a ^ b))) + (((const union unaligned_32 *)(X + (((32 + 8) + 2) & 15)))->l);
            else
                c += ((b & d) | (~b & a)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((32 + 8) + 2)) & 15)))->l);
        } else {
            if (((32 + 8) + 2) < 48)
                c += (d ^ a ^ b) + (((const union unaligned_32 *)(X + ((5 + 3 * ((32 + 8) + 2)) & 15)))->l);
            else
                c += (a ^ (d | ~b)) + (((const union unaligned_32 *)(X + ((7 * ((32 + 8) + 2)) & 15)))->l);
        }
        c = d + (c << t | c >> (32 - t));
    } while (0);
    do {
        t = S[((32 + 8) + 3) >> 4][((32 + 8) + 3) & 3];
        b += T[((32 + 8) + 3)];
        if (((32 + 8) + 3) < 32) {
            if (((32 + 8) + 3) < 16)
                b += (a ^ (c & (d ^ a))) + (((const union unaligned_32 *)(X + (((32 + 8) + 3) & 15)))->l);
            else
                b += ((a & c) | (~a & d)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((32 + 8) + 3)) & 15)))->l);
        } else {
            if (((32 + 8) + 3) < 48)
                b += (c ^ d ^ a) + (((const union unaligned_32 *)(X + ((5 + 3 * ((32 + 8) + 3)) & 15)))->l);
            else
                b += (d ^ (c | ~a)) + (((const union unaligned_32 *)(X + ((7 * ((32 + 8) + 3)) & 15)))->l);
        }
        b = c + (b << t | b >> (32 - t));
    } while (0);
    do {
        t = S[(32 + 12) >> 4][(32 + 12) & 3];
        a += T[(32 + 12)];
        if ((32 + 12) < 32) {
            if ((32 + 12) < 16)
                a += (d ^ (b & (c ^ d))) + (((const union unaligned_32 *)(X + ((32 + 12) & 15)))->l);
            else
                a += ((d & b) | (~d & c)) + (((const union unaligned_32 *)(X + ((1 + 5 * (32 + 12)) & 15)))->l);
        } else {
            if ((32 + 12) < 48)
                a += (b ^ c ^ d) + (((const union unaligned_32 *)(X + ((5 + 3 * (32 + 12)) & 15)))->l);
            else
                a += (c ^ (b | ~d)) + (((const union unaligned_32 *)(X + ((7 * (32 + 12)) & 15)))->l);
        }
        a = b + (a << t | a >> (32 - t));
    } while (0);
    do {
        t = S[((32 + 12) + 1) >> 4][((32 + 12) + 1) & 3];
        d += T[((32 + 12) + 1)];
        if (((32 + 12) + 1) < 32) {
            if (((32 + 12) + 1) < 16)
                d += (c ^ (a & (b ^ c))) + (((const union unaligned_32 *)(X + (((32 + 12) + 1) & 15)))->l);
            else
                d += ((c & a) | (~c & b)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((32 + 12) + 1)) & 15)))->l);
        } else {
            if (((32 + 12) + 1) < 48)
                d += (a ^ b ^ c) + (((const union unaligned_32 *)(X + ((5 + 3 * ((32 + 12) + 1)) & 15)))->l);
            else
                d += (b ^ (a | ~c)) + (((const union unaligned_32 *)(X + ((7 * ((32 + 12) + 1)) & 15)))->l);
        }
        d = a + (d << t | d >> (32 - t));
    } while (0);
    do {
        t = S[((32 + 12) + 2) >> 4][((32 + 12) + 2) & 3];
        c += T[((32 + 12) + 2)];
        if (((32 + 12) + 2) < 32) {
            if (((32 + 12) + 2) < 16)
                c += (b ^ (d & (a ^ b))) + (((const union unaligned_32 *)(X + (((32 + 12) + 2) & 15)))->l);
            else
                c += ((b & d) | (~b & a)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((32 + 12) + 2)) & 15)))->l);
        } else {
            if (((32 + 12) + 2) < 48)
                c += (d ^ a ^ b) + (((const union unaligned_32 *)(X + ((5 + 3 * ((32 + 12) + 2)) & 15)))->l);
            else
                c += (a ^ (d | ~b)) + (((const union unaligned_32 *)(X + ((7 * ((32 + 12) + 2)) & 15)))->l);
        }
        c = d + (c << t | c >> (32 - t));
    } while (0);
    do {
        t = S[((32 + 12) + 3) >> 4][((32 + 12) + 3) & 3];
        b += T[((32 + 12) + 3)];
        if (((32 + 12) + 3) < 32) {
            if (((32 + 12) + 3) < 16)
                b += (a ^ (c & (d ^ a))) + (((const union unaligned_32 *)(X + (((32 + 12) + 3) & 15)))->l);
            else
                b += ((a & c) | (~a & d)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((32 + 12) + 3)) & 15)))->l);
        } else {
            if (((32 + 12) + 3) < 48)
                b += (c ^ d ^ a) + (((const union unaligned_32 *)(X + ((5 + 3 * ((32 + 12) + 3)) & 15)))->l);
            else
                b += (d ^ (c | ~a)) + (((const union unaligned_32 *)(X + ((7 * ((32 + 12) + 3)) & 15)))->l);
        }
        b = c + (b << t | b >> (32 - t));
    } while (0);
    do {
        t = S[48 >> 4][48 & 3];
        a += T[48];
        if (48 < 32) {
            if (48 < 16)
                a += (d ^ (b & (c ^ d))) + (((const union unaligned_32 *)(X + (48 & 15)))->l);
            else
                a += ((d & b) | (~d & c)) + (((const union unaligned_32 *)(X + ((1 + 5 * 48) & 15)))->l);
        } else {
            if (48 < 48)
                a += (b ^ c ^ d) + (((const union unaligned_32 *)(X + ((5 + 3 * 48) & 15)))->l);
            else
                a += (c ^ (b | ~d)) + (((const union unaligned_32 *)(X + ((7 * 48) & 15)))->l);
        }
        a = b + (a << t | a >> (32 - t));
    } while (0);
    do {
        t = S[(48 + 1) >> 4][(48 + 1) & 3];
        d += T[(48 + 1)];
        if ((48 + 1) < 32) {
            if ((48 + 1) < 16)
                d += (c ^ (a & (b ^ c))) + (((const union unaligned_32 *)(X + ((48 + 1) & 15)))->l);
            else
                d += ((c & a) | (~c & b)) + (((const union unaligned_32 *)(X + ((1 + 5 * (48 + 1)) & 15)))->l);
        } else {
            if ((48 + 1) < 48)
                d += (a ^ b ^ c) + (((const union unaligned_32 *)(X + ((5 + 3 * (48 + 1)) & 15)))->l);
            else
                d += (b ^ (a | ~c)) + (((const union unaligned_32 *)(X + ((7 * (48 + 1)) & 15)))->l);
        }
        d = a + (d << t | d >> (32 - t));
    } while (0);
    do {
        t = S[(48 + 2) >> 4][(48 + 2) & 3];
        c += T[(48 + 2)];
        if ((48 + 2) < 32) {
            if ((48 + 2) < 16)
                c += (b ^ (d & (a ^ b))) + (((const union unaligned_32 *)(X + ((48 + 2) & 15)))->l);
            else
                c += ((b & d) | (~b & a)) + (((const union unaligned_32 *)(X + ((1 + 5 * (48 + 2)) & 15)))->l);
        } else {
            if ((48 + 2) < 48)
                c += (d ^ a ^ b) + (((const union unaligned_32 *)(X + ((5 + 3 * (48 + 2)) & 15)))->l);
            else
                c += (a ^ (d | ~b)) + (((const union unaligned_32 *)(X + ((7 * (48 + 2)) & 15)))->l);
        }
        c = d + (c << t | c >> (32 - t));
    } while (0);
    do {
        t = S[(48 + 3) >> 4][(48 + 3) & 3];
        b += T[(48 + 3)];
        if ((48 + 3) < 32) {
            if ((48 + 3) < 16)
                b += (a ^ (c & (d ^ a))) + (((const union unaligned_32 *)(X + ((48 + 3) & 15)))->l);
            else
                b += ((a & c) | (~a & d)) + (((const union unaligned_32 *)(X + ((1 + 5 * (48 + 3)) & 15)))->l);
        } else {
            if ((48 + 3) < 48)
                b += (c ^ d ^ a) + (((const union unaligned_32 *)(X + ((5 + 3 * (48 + 3)) & 15)))->l);
            else
                b += (d ^ (c | ~a)) + (((const union unaligned_32 *)(X + ((7 * (48 + 3)) & 15)))->l);
        }
        b = c + (b << t | b >> (32 - t));
    } while (0);
    do {
        t = S[(48 + 4) >> 4][(48 + 4) & 3];
        a += T[(48 + 4)];
        if ((48 + 4) < 32) {
            if ((48 + 4) < 16)
                a += (d ^ (b & (c ^ d))) + (((const union unaligned_32 *)(X + ((48 + 4) & 15)))->l);
            else
                a += ((d & b) | (~d & c)) + (((const union unaligned_32 *)(X + ((1 + 5 * (48 + 4)) & 15)))->l);
        } else {
            if ((48 + 4) < 48)
                a += (b ^ c ^ d) + (((const union unaligned_32 *)(X + ((5 + 3 * (48 + 4)) & 15)))->l);
            else
                a += (c ^ (b | ~d)) + (((const union unaligned_32 *)(X + ((7 * (48 + 4)) & 15)))->l);
        }
        a = b + (a << t | a >> (32 - t));
    } while (0);
    do {
        t = S[((48 + 4) + 1) >> 4][((48 + 4) + 1) & 3];
        d += T[((48 + 4) + 1)];
        if (((48 + 4) + 1) < 32) {
            if (((48 + 4) + 1) < 16)
                d += (c ^ (a & (b ^ c))) + (((const union unaligned_32 *)(X + (((48 + 4) + 1) & 15)))->l);
            else
                d += ((c & a) | (~c & b)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((48 + 4) + 1)) & 15)))->l);
        } else {
            if (((48 + 4) + 1) < 48)
                d += (a ^ b ^ c) + (((const union unaligned_32 *)(X + ((5 + 3 * ((48 + 4) + 1)) & 15)))->l);
            else
                d += (b ^ (a | ~c)) + (((const union unaligned_32 *)(X + ((7 * ((48 + 4) + 1)) & 15)))->l);
        }
        d = a + (d << t | d >> (32 - t));
    } while (0);
    do {
        t = S[((48 + 4) + 2) >> 4][((48 + 4) + 2) & 3];
        c += T[((48 + 4) + 2)];
        if (((48 + 4) + 2) < 32) {
            if (((48 + 4) + 2) < 16)
                c += (b ^ (d & (a ^ b))) + (((const union unaligned_32 *)(X + (((48 + 4) + 2) & 15)))->l);
            else
                c += ((b & d) | (~b & a)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((48 + 4) + 2)) & 15)))->l);
        } else {
            if (((48 + 4) + 2) < 48)
                c += (d ^ a ^ b) + (((const union unaligned_32 *)(X + ((5 + 3 * ((48 + 4) + 2)) & 15)))->l);
            else
                c += (a ^ (d | ~b)) + (((const union unaligned_32 *)(X + ((7 * ((48 + 4) + 2)) & 15)))->l);
        }
        c = d + (c << t | c >> (32 - t));
    } while (0);
    do {
        t = S[((48 + 4) + 3) >> 4][((48 + 4) + 3) & 3];
        b += T[((48 + 4) + 3)];
        if (((48 + 4) + 3) < 32) {
            if (((48 + 4) + 3) < 16)
                b += (a ^ (c & (d ^ a))) + (((const union unaligned_32 *)(X + (((48 + 4) + 3) & 15)))->l);
            else
                b += ((a & c) | (~a & d)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((48 + 4) + 3)) & 15)))->l);
        } else {
            if (((48 + 4) + 3) < 48)
                b += (c ^ d ^ a) + (((const union unaligned_32 *)(X + ((5 + 3 * ((48 + 4) + 3)) & 15)))->l);
            else
                b += (d ^ (c | ~a)) + (((const union unaligned_32 *)(X + ((7 * ((48 + 4) + 3)) & 15)))->l);
        }
        b = c + (b << t | b >> (32 - t));
    } while (0);
    do {
        t = S[(48 + 8) >> 4][(48 + 8) & 3];
        a += T[(48 + 8)];
        if ((48 + 8) < 32) {
            if ((48 + 8) < 16)
                a += (d ^ (b & (c ^ d))) + (((const union unaligned_32 *)(X + ((48 + 8) & 15)))->l);
            else
                a += ((d & b) | (~d & c)) + (((const union unaligned_32 *)(X + ((1 + 5 * (48 + 8)) & 15)))->l);
        } else {
            if ((48 + 8) < 48)
                a += (b ^ c ^ d) + (((const union unaligned_32 *)(X + ((5 + 3 * (48 + 8)) & 15)))->l);
            else
                a += (c ^ (b | ~d)) + (((const union unaligned_32 *)(X + ((7 * (48 + 8)) & 15)))->l);
        }
        a = b + (a << t | a >> (32 - t));
    } while (0);
    do {
        t = S[((48 + 8) + 1) >> 4][((48 + 8) + 1) & 3];
        d += T[((48 + 8) + 1)];
        if (((48 + 8) + 1) < 32) {
            if (((48 + 8) + 1) < 16)
                d += (c ^ (a & (b ^ c))) + (((const union unaligned_32 *)(X + (((48 + 8) + 1) & 15)))->l);
            else
                d += ((c & a) | (~c & b)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((48 + 8) + 1)) & 15)))->l);
        } else {
            if (((48 + 8) + 1) < 48)
                d += (a ^ b ^ c) + (((const union unaligned_32 *)(X + ((5 + 3 * ((48 + 8) + 1)) & 15)))->l);
            else
                d += (b ^ (a | ~c)) + (((const union unaligned_32 *)(X + ((7 * ((48 + 8) + 1)) & 15)))->l);
        }
        d = a + (d << t | d >> (32 - t));
    } while (0);
    do {
        t = S[((48 + 8) + 2) >> 4][((48 + 8) + 2) & 3];
        c += T[((48 + 8) + 2)];
        if (((48 + 8) + 2) < 32) {
            if (((48 + 8) + 2) < 16)
                c += (b ^ (d & (a ^ b))) + (((const union unaligned_32 *)(X + (((48 + 8) + 2) & 15)))->l);
            else
                c += ((b & d) | (~b & a)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((48 + 8) + 2)) & 15)))->l);
        } else {
            if (((48 + 8) + 2) < 48)
                c += (d ^ a ^ b) + (((const union unaligned_32 *)(X + ((5 + 3 * ((48 + 8) + 2)) & 15)))->l);
            else
                c += (a ^ (d | ~b)) + (((const union unaligned_32 *)(X + ((7 * ((48 + 8) + 2)) & 15)))->l);
        }
        c = d + (c << t | c >> (32 - t));
    } while (0);
    do {
        t = S[((48 + 8) + 3) >> 4][((48 + 8) + 3) & 3];
        b += T[((48 + 8) + 3)];
        if (((48 + 8) + 3) < 32) {
            if (((48 + 8) + 3) < 16)
                b += (a ^ (c & (d ^ a))) + (((const union unaligned_32 *)(X + (((48 + 8) + 3) & 15)))->l);
            else
                b += ((a & c) | (~a & d)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((48 + 8) + 3)) & 15)))->l);
        } else {
            if (((48 + 8) + 3) < 48)
                b += (c ^ d ^ a) + (((const union unaligned_32 *)(X + ((5 + 3 * ((48 + 8) + 3)) & 15)))->l);
            else
                b += (d ^ (c | ~a)) + (((const union unaligned_32 *)(X + ((7 * ((48 + 8) + 3)) & 15)))->l);
        }
        b = c + (b << t | b >> (32 - t));
    } while (0);
    do {
        t = S[(48 + 12) >> 4][(48 + 12) & 3];
        a += T[(48 + 12)];
        if ((48 + 12) < 32) {
            if ((48 + 12) < 16)
                a += (d ^ (b & (c ^ d))) + (((const union unaligned_32 *)(X + ((48 + 12) & 15)))->l);
            else
                a += ((d & b) | (~d & c)) + (((const union unaligned_32 *)(X + ((1 + 5 * (48 + 12)) & 15)))->l);
        } else {
            if ((48 + 12) < 48)
                a += (b ^ c ^ d) + (((const union unaligned_32 *)(X + ((5 + 3 * (48 + 12)) & 15)))->l);
            else
                a += (c ^ (b | ~d)) + (((const union unaligned_32 *)(X + ((7 * (48 + 12)) & 15)))->l);
        }
        a = b + (a << t | a >> (32 - t));
    } while (0);
    do {
        t = S[((48 + 12) + 1) >> 4][((48 + 12) + 1) & 3];
        d += T[((48 + 12) + 1)];
        if (((48 + 12) + 1) < 32) {
            if (((48 + 12) + 1) < 16)
                d += (c ^ (a & (b ^ c))) + (((const union unaligned_32 *)(X + (((48 + 12) + 1) & 15)))->l);
            else
                d += ((c & a) | (~c & b)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((48 + 12) + 1)) & 15)))->l);
        } else {
            if (((48 + 12) + 1) < 48)
                d += (a ^ b ^ c) + (((const union unaligned_32 *)(X + ((5 + 3 * ((48 + 12) + 1)) & 15)))->l);
            else
                d += (b ^ (a | ~c)) + (((const union unaligned_32 *)(X + ((7 * ((48 + 12) + 1)) & 15)))->l);
        }
        d = a + (d << t | d >> (32 - t));
    } while (0);
    do {
        t = S[((48 + 12) + 2) >> 4][((48 + 12) + 2) & 3];
        c += T[((48 + 12) + 2)];
        if (((48 + 12) + 2) < 32) {
            if (((48 + 12) + 2) < 16)
                c += (b ^ (d & (a ^ b))) + (((const union unaligned_32 *)(X + (((48 + 12) + 2) & 15)))->l);
            else
                c += ((b & d) | (~b & a)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((48 + 12) + 2)) & 15)))->l);
        } else {
            if (((48 + 12) + 2) < 48)
                c += (d ^ a ^ b) + (((const union unaligned_32 *)(X + ((5 + 3 * ((48 + 12) + 2)) & 15)))->l);
            else
                c += (a ^ (d | ~b)) + (((const union unaligned_32 *)(X + ((7 * ((48 + 12) + 2)) & 15)))->l);
        }
        c = d + (c << t | c >> (32 - t));
    } while (0);
    do {
        t = S[((48 + 12) + 3) >> 4][((48 + 12) + 3) & 3];
        b += T[((48 + 12) + 3)];
        if (((48 + 12) + 3) < 32) {
            if (((48 + 12) + 3) < 16)
                b += (a ^ (c & (d ^ a))) + (((const union unaligned_32 *)(X + (((48 + 12) + 3) & 15)))->l);
            else
                b += ((a & c) | (~a & d)) + (((const union unaligned_32 *)(X + ((1 + 5 * ((48 + 12) + 3)) & 15)))->l);
        } else {
            if (((48 + 12) + 3) < 48)
                b += (c ^ d ^ a) + (((const union unaligned_32 *)(X + ((5 + 3 * ((48 + 12) + 3)) & 15)))->l);
            else
                b += (d ^ (c | ~a)) + (((const union unaligned_32 *)(X + ((7 * ((48 + 12) + 3)) & 15)))->l);
        }
        b = c + (b << t | b >> (32 - t));
    } while (0);
    ABCD[0] += d;
    ABCD[1] += c;
    ABCD[2] += b;
    ABCD[3] += a;
}

}
