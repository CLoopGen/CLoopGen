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
    for (i = 0; n-- > 0; i++) {
        unsigned long l = 0;
        unsigned int m = 0;
        int stride = inc * 2; // Strided access with step of 2*inc
        for (; len > 0 && m < 8 * 8; len -= 2, s += stride, m += 16) {
            if (len >= 1) {
                unsigned long byte_xored = *s ^ xor;
                unsigned long byte = (byte_xored + carry) & 255;
                carry = byte_xored > byte;
                l |= (byte << m);
            }
            if (len >= 2) {
                unsigned long byte_xored_next = *(s + inc) ^ xor;
                unsigned long byte_next = (byte_xored_next + carry) & 255;
                carry = byte_xored_next > byte_next;
                l |= (byte_next << (m + 8));
            }
        }
        ret->d[i] = l;
    }
}
