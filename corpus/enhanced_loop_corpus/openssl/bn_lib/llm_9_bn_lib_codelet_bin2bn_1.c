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
    for (i = 0; i < (n + 3) / 4 && len > 0; i += 4) {
        unsigned long l0 = 0, l1 = 0, l2 = 0, l3 = 0;
        unsigned int m0 = 0, m1 = 0, m2 = 0, m3 = 0;
        unsigned int temp_carry = carry;

        for (int j = 0; j < 2 && len > 0; j++) {
            unsigned long byte_xored = *s ^ xor;
            unsigned long byte = (byte_xored + temp_carry) & 255;
            temp_carry = byte_xored > byte;
            if (j == 0) {
                l0 |= (byte << m0); m0 += 8;
                if (++len > 0 && (s += inc, len), m0 < 64) {
                    byte_xored = *s ^ xor;
                    byte = (byte_xored + temp_carry) & 255;
                    temp_carry = byte_xored > byte;
                    l1 |= (byte << m1); m1 += 8;
                }
            } else {
                l2 |= (byte << m2); m2 += 8;
                if (++len > 0 && (s += inc, len), m2 < 64) {
                    byte_xored = *s ^ xor;
                    byte = (byte_xored + temp_carry) & 255;
                    temp_carry = byte_xored > byte;
                    l3 |= (byte << m3); m3 += 8;
                }
            }
        }

        ret->d[i + 0] = l0;
        if (i + 1 < n) ret->d[i + 1] = l1;
        if (i + 2 < n) ret->d[i + 2] = l2;
        if (i + 3 < n) ret->d[i + 3] = l3;
        carry = temp_carry;
    }
}
