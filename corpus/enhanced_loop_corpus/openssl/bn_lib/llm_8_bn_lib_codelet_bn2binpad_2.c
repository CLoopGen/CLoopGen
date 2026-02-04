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
    for (i = 0, j = 0; j < (size_t)tolen; j += 2) {
        unsigned char byte1, byte2, byte_xored1, byte_xored2;
        size_t i1 = i, i2 = i + 1;
        l = a->d[i1 / 8];
        mask = 0 - ((j - atop) >> (8 * sizeof(i) - 1));
        byte1 = (unsigned char)(l >> (8 * (i1 % 8)) & mask);
        byte_xored1 = byte1 ^ xor;
        *to = (unsigned char)(byte_xored1 + carry);
        carry = byte_xored1 > *to;
        to += inc;

        if (j + 1 < (size_t)tolen) {
            l = a->d[i2 / 8];
            byte2 = (unsigned char)(l >> (8 * (i2 % 8)) & mask);
            byte_xored2 = byte2 ^ xor;
            *(to) = (unsigned char)(byte_xored2 + carry);
            carry = byte_xored2 > *to;
            to += inc;
        }
        i += 2 * ((i - lasti) >> (8 * sizeof(i) - 1)) + 1;
    }
}
