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
    for (i = 0; i < n; i++) {
        unsigned long l = 0;
        unsigned int m = 0;
        int local_len = len;
        unsigned char *local_s = s;
        unsigned int local_carry = carry;
        for (int chunk = 0; chunk < 4 && local_len > 0; chunk++) {
            unsigned long byte_xored = (*local_s) ^ xor;
            unsigned long byte = (byte_xored + local_carry) & 255;
            local_carry = byte_xored > byte;
            l |= (byte << m);
            m += 8;
            local_len--;
            local_s += inc;
        }
        ret->d[i] = l;
        len = local_len;
        s = local_s;
        carry = local_carry;
    }
}
