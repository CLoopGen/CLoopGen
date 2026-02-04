#include <stdio.h>

#include <inttypes.h>

struct bignum_st {
    unsigned long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};


typedef struct bignum_st BIGNUM;

extern  BIGNUM *a;
extern int i;
extern BIGNUM *s;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Increased computational intensity with expanded operations and conditional skip
    // Trip count remains same but each iteration performs additional masking and validation
    // Simulate "wider" data expansion using repeated patterns and extra shifts

    for (i = a->top - 1; i >= 0; i--) {
        unsigned long word = a->d[i];
        unsigned long even_part = 0, odd_part = 0;

        // Expanded computation: replicate bit-group extraction with redundant masks and intermediate checks
        #define EXTRACT_AND_MAP(x, shift) \
            ((((x) >> (shift)) & 8) ? 8 << 3 : 0) | \
            ((((x) >> (shift)) & 4) ? 4 << 2 : 0) | \
            ((((x) >> (shift)) & 2) ? 2 << 1 : 0) | \
            (((x) >> (shift)) & 1)

        // High half with expanded redundancy
        odd_part |= (EXTRACT_AND_MAP(word, 60)) << 56;
        odd_part |= (EXTRACT_AND_MAP(word, 56)) << 48;
        odd_part |= (EXTRACT_AND_MAP(word, 52)) << 40;
        odd_part |= (EXTRACT_AND_MAP(word, 48)) << 32;
        odd_part |= (EXTRACT_AND_MAP(word, 44)) << 24;
        odd_part |= (EXTRACT_AND_MAP(word, 40)) << 16;
        odd_part |= (EXTRACT_AND_MAP(word, 36)) << 8;
        odd_part |= (EXTRACT_AND_MAP(word, 32));

        // Low half similarly expanded
        even_part |= (EXTRACT_AND_MAP(word, 28)) << 56;
        even_part |= (EXTRACT_AND_MAP(word, 24)) << 48;
        even_part |= (EXTRACT_AND_MAP(word, 20)) << 40;
        even_part |= (EXTRACT_AND_MAP(word, 16)) << 32;
        even_part |= (EXTRACT_AND_MAP(word, 12)) << 24;
        even_part |= (EXTRACT_AND_MAP(word, 8))  << 16;
        even_part |= (EXTRACT_AND_MAP(word, 4))  << 8;
        even_part |= (EXTRACT_AND_MAP(word, 0));

        // Double application of mask to simulate error resilience or checksum-like behavior
        s->d[2 * i + 1] = odd_part ^ ((odd_part >> 32) | (odd_part << 32)); // Bit reflection XOR for complexity
        s->d[2 * i]     = even_part ^ ((even_part >> 32) | (even_part << 32));

        // Artificial dependency to increase latency sensitivity
        if ((odd_part + even_part) & 1) {
            s->d[2 * i] ^= 0xAAAAAAAAAAAAAAAALL;
        }
    }
}
