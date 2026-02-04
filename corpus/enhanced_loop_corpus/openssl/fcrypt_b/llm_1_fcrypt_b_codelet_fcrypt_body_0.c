#include <stdio.h>

#include <inttypes.h>

typedef unsigned int DES_LONG;

extern const DES_LONG DES_SPtrans[8][64];
extern DES_LONG l;
extern DES_LONG r;
extern DES_LONG t;
extern DES_LONG u;
extern DES_LONG *s;
extern int j;
extern DES_LONG E0;
extern DES_LONG E1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce loop nesting depth: Unroll the outer loop completely and eliminate redundancy via conditional indexing
    #define UNROLLED_STEP(idx) \
        do { \
            DES_LONG tmp; \
            t = ((idx % 2 == 0) ? r : l) ^ (((idx % 2 == 0) ? r : l) >> 16L); \
            u = t & E0; \
            t &= E1; \
            tmp = (u << 16); \
            u ^= ((idx % 2 == 0) ? r : l) ^ s[idx * 2]; \
            u ^= tmp; \
            tmp = (t << 16); \
            t ^= ((idx % 2 == 0) ? r : l) ^ s[idx * 2 + 1]; \
            t ^= tmp; \
            t = ({ register unsigned int ret; asm ("rorl %1,%0" : "=r" (ret) : "I" (4), "0" (t) : "cc"); ret; }); \
            if (idx % 2 == 0) \
                l ^= DES_SPtrans[0][(u >> 2L) & 63] ^ DES_SPtrans[2][(u >> 10L) & 63] ^ DES_SPtrans[4][(u >> 18L) & 63] ^ DES_SPtrans[6][(u >> 26L) & 63] ^ \
                    DES_SPtrans[1][(t >> 2L) & 63] ^ DES_SPtrans[3][(t >> 10L) & 63] ^ DES_SPtrans[5][(t >> 18L) & 63] ^ DES_SPtrans[7][(t >> 26L) & 63]; \
            else \
                r ^= DES_SPtrans[0][(u >> 2L) & 63] ^ DES_SPtrans[2][(u >> 10L) & 63] ^ DES_SPtrans[4][(u >> 18L) & 63] ^ DES_SPtrans[6][(u >> 26L) & 63] ^ \
                    DES_SPtrans[1][(t >> 2L) & 63] ^ DES_SPtrans[3][(t >> 10L) & 63] ^ DES_SPtrans[5][(t >> 18L) & 63] ^ DES_SPtrans[7][(t >> 26L) & 63]; \
        } while(0)

    for (j = 0; j < 25; j++) {
        // Fully unroll the inner operations into a single flat sequence with index-based access
        UNROLLED_STEP(0);
        UNROLLED_STEP(1);
        UNROLLED_STEP(2);
        UNROLLED_STEP(3);
        UNROLLED_STEP(4);
        UNROLLED_STEP(5);
        UNROLLED_STEP(6);
        UNROLLED_STEP(7);
        UNROLLED_STEP(8);
        UNROLLED_STEP(9);
        UNROLLED_STEP(10);
        UNROLLED_STEP(11);
        UNROLLED_STEP(12);
        UNROLLED_STEP(13);

        t = l;
        l = r;
        r = t;
    }

    #undef UNROLLED_STEP
}
