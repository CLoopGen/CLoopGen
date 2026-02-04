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
    for (int round = 0; round < 4; round++) {
        int base = round * 16;
        for (int offset = 0; offset < 16; offset += 4) {
            int idx = base + offset;
            for (int step = 0; step < 4; step++) {
                int i = idx + step;
                t = S[i >> 4][i & 3];
                uint32_t temp_sum;
                switch (step) {
                    case 0: // a update
                        a += T[i];
                        if (i < 32) {
                            if (i < 16)
                                temp_sum = (d ^ (b & (c ^ d))) + (((const union unaligned_32 *)(X + (i & 15)))->l);
                            else
                                temp_sum = ((d & b) | (~d & c)) + (((const union unaligned_32 *)(X + ((1 + 5 * i) & 15)))->l);
                        } else {
                            if (i < 48)
                                temp_sum = (b ^ c ^ d) + (((const union unaligned_32 *)(X + ((5 + 3 * i) & 15)))->l);
                            else
                                temp_sum = (c ^ (b | ~d)) + (((const union unaligned_32 *)(X + ((7 * i) & 15)))->l);
                        }
                        a = b + (a << t | a >> (32 - t));
                        break;
                    case 1: // d update
                        d += T[i];
                        if (i < 32) {
                            if (i < 16)
                                temp_sum = (c ^ (a & (b ^ c))) + (((const union unaligned_32 *)(X + (i & 15)))->l);
                            else
                                temp_sum = ((c & a) | (~c & b)) + (((const union unaligned_32 *)(X + ((1 + 5 * i) & 15)))->l);
                        } else {
                            if (i < 48)
                                temp_sum = (a ^ b ^ c) + (((const union unaligned_32 *)(X + ((5 + 3 * i) & 15)))->l);
                            else
                                temp_sum = (b ^ (a | ~c)) + (((const union unaligned_32 *)(X + ((7 * i) & 15)))->l);
                        }
                        d = a + (d << t | d >> (32 - t));
                        break;
                    case 2: // c update
                        c += T[i];
                        if (i < 32) {
                            if (i < 16)
                                temp_sum = (b ^ (d & (a ^ b))) + (((const union unaligned_32 *)(X + (i & 15)))->l);
                            else
                                temp_sum = ((b & d) | (~b & a)) + (((const union unaligned_32 *)(X + ((1 + 5 * i) & 15)))->l);
                        } else {
                            if (i < 48)
                                temp_sum = (d ^ a ^ b) + (((const union unaligned_32 *)(X + ((5 + 3 * i) & 15)))->l);
                            else
                                temp_sum = (a ^ (d | ~b)) + (((const union unaligned_32 *)(X + ((7 * i) & 15)))->l);
                        }
                        c = d + (c << t | c >> (32 - t));
                        break;
                    case 3: // b update
                        b += T[i];
                        if (i < 32) {
                            if (i < 16)
                                temp_sum = (a ^ (c & (d ^ a))) + (((const union unaligned_32 *)(X + (i & 15)))->l);
                            else
                                temp_sum = ((a & c) | (~a & d)) + (((const union unaligned_32 *)(X + ((1 + 5 * i) & 15)))->l);
                        } else {
                            if (i < 48)
                                temp_sum = (c ^ d ^ a) + (((const union unaligned_32 *)(X + ((5 + 3 * i) & 15)))->l);
                            else
                                temp_sum = (d ^ (c | ~a)) + (((const union unaligned_32 *)(X + ((7 * i) & 15)))->l);
                        }
                        b = c + (b << t | b >> (32 - t));
                        break;
                }
            }
        }
    }
    ABCD[0] += d;
    ABCD[1] += c;
    ABCD[2] += b;
    ABCD[3] += a;
}
}
