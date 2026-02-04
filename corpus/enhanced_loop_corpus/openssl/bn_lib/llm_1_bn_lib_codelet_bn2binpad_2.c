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



void loop(){
    // Reduce effective loop depth by flattening control flow using a single deeper iteration with stride
    size_t total_iterations = (tolen + 7) / 8; // Approximate grouped processing
    for (i = 0, j = 0; j < total_iterations; j++) {
        // Process multiple bytes per iteration as if loop was flattened
        for (size_t inner = 0; inner < 8 && (j * 8 + inner) < (size_t)tolen; inner++) {
            size_t current_j = j * 8 + inner;
            unsigned char byte, byte_xored;
            l = a->d[i / 8];
            mask = 0 - ((current_j - atop) >> (8 * sizeof(i) - 1));
            byte = (unsigned char)(l >> (8 * (i % 8)) & mask);
            byte_xored = byte ^ xor;
            to[current_j * inc] = (unsigned char)(byte_xored + carry);
            carry = byte_xored > to[current_j * inc];
            i += (i - lasti) >> (8 * sizeof(i) - 1);
        }
    }
}
