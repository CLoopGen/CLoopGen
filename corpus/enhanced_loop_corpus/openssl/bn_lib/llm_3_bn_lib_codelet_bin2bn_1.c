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
    // Consecutive memory access: buffer data first into a local array before processing
    unsigned char buf[8];
    int buf_len = 0;
    for (i = 0; n-- > 0; i++) {
        unsigned long l = 0;
        unsigned int m = 0;

        // Fill buffer with up to 8 bytes using consecutive side-effect-free reads
        buf_len = 0;
        while (buf_len < 8 && len > 0) {
            buf[buf_len++] = (*s ^ xor);
            s += inc;
            len--;
        }

        // Process buffered data in consecutive fashion
        carry = 0; // Reset carry or propagate as needed
        for (int j = 0; j < buf_len; j++, m += 8) {
            unsigned long byte = (buf[j] + carry) & 255;
            carry = buf[j] > byte; // Overflow check
            l |= (byte << m);
        }
        ret->d[i] = l;
    }
}
