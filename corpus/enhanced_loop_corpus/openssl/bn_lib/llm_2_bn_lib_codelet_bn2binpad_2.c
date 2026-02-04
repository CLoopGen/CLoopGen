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
extern unsigned char *to;
extern int tolen;
extern int inc;
extern int xor;
extern int carry;
extern size_t i;
extern size_t lasti;
extern size_t j;
extern size_t atop;
extern size_t mask;
extern unsigned long l;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access with Prefetched Indexing
    // Changed access pattern to process BIGNUM digits in a more cache-friendly, consecutive manner.
    // Instead of bit-granular indexing (i / 8, i % 8), we now traverse full unsigned longs and unpack bytes sequentially.
    size_t word_index = 0;
    size_t byte_in_word = 0;
    unsigned long current_word = 0;

    for (j = 0; j < (size_t)tolen; j++) {
        unsigned char byte, byte_xored;

        // Load new word when needed (every 8th byte)
        if (byte_in_word == 0) {
            current_word = (word_index < (size_t)a->top) ? a->d[word_index] : 0;
        }

        byte = (unsigned char)((current_word >> (8 * byte_in_word)) & 0xFF);
        // Apply masking based on position relative to 'atop'
        mask = 0 - ((j >= atop));
        byte &= mask;

        byte_xored = byte ^ xor;
        *to = (unsigned char)(byte_xored + carry);
        carry = (byte_xored > *to);
        to += inc;

        // Update indices: move to next byte in word, wrap every 8 bytes
        byte_in_word = (byte_in_word + 1) % 8;
        word_index += (byte_in_word == 0);  // Advance word index only when finishing a word
    }
}
