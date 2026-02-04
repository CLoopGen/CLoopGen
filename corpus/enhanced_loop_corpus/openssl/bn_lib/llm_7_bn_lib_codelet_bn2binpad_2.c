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
        unsigned char byte = 0, byte_xored;
        size_t current_i_div8 = i / 8;
        size_t current_i_mod8 = i % 8;
        l = a->d[current_i_div8];
        mask = (j >= atop) ? 0xFF : 0x00;
        byte = (unsigned char)((l >> (8 * current_i_mod8)) & mask);
        byte_xored = byte ^ xor;
        unsigned char sum = byte_xored + carry;
        carry = (sum < byte_xored);
        *to = sum;
        to += inc;
        if (i >= lasti) {
            i++;
        }
    }
}
