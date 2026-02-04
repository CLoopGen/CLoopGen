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
    for (i = 0, j = 0; j < (size_t)tolen; j++) {
        unsigned char byte, byte_xored;
        size_t index = i / 8;
        l = a->d[index];
        mask = 0 - ((j - atop) >> (8 * sizeof(i) - 1));
        byte = (unsigned char)((l >> (8 * (i % 8))) & mask);
        byte_xored = byte ^ xor;
        unsigned char new_byte = (unsigned char)(byte_xored + carry);
        carry = (byte_xored > new_byte) ? 1 : 0;
        *to = new_byte;
        to += inc;
        size_t diff = i - lasti;
        i += (diff >> (8 * sizeof(i) - 1)) & 1;
    }
}
