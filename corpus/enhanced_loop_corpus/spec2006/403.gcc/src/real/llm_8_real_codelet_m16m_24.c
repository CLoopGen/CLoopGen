#include <stdio.h>

#include <inttypes.h>

extern unsigned short *pp;
extern unsigned int carry;
extern  unsigned short *ps;
extern unsigned int aa;
extern unsigned int m;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 3; i < 8; i += 2) {
    if (*ps == 0) {
        ps -= 2;
        pp -= 2;
        *(pp - 1) = 0;
        *(pp - 2) = 0;
    } else {
        m = (unsigned int)aa * *ps--;
        carry = (m & 65535) + *pp;
        *pp-- = (unsigned short)carry;
        carry = (carry >> 16) + (m >> 16) + *pp;
        *pp = (unsigned short)carry;
        *(pp - 1) = carry >> 16;
    }
}
}
