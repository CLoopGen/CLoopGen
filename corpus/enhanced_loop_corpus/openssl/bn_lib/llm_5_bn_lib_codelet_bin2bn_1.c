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

extern  unsigned char *s;
extern int len;
extern BIGNUM *ret;
extern int inc;
extern int xor;
extern int carry;
extern unsigned int i;
extern unsigned int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; n > 0 && len > 0; i++, n--) {
        unsigned long l = 0;
        unsigned int m = 0;
        for (; m < 64 && len > 0; m += 8, len--, s += inc) {
            unsigned long byte_xored = (*s ^ xor);
            carry = (byte_xored + carry) > 255 ? 1 : 0;
            unsigned long byte = (byte_xored + carry) & 255;
            l |= (byte << m);
            if (m >= 64 - 8) break;
        }
        ret->d[i] = l;
    }
}
