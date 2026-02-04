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
    // Variant 1: Strided memory access with stride of 2 on ps and pp
    for (i = 2 + 1; i < (6 + 3); i++) {
        if (*(ps - (i - 3)*2) == 0) {  // strided read from ps
            --ps;
            --pp;
            *(pp - 1) = 0;
        } else {
            m = (unsigned int)aa * *(ps - (i - 3)*2);
            carry = (m & 65535) + *(pp - (i - 3)*2);
            *(pp - (i - 3)*2) = (unsigned short)carry;
            carry = (carry >> 16) + (m >> 16) + *(pp - (i - 3)*2 - 1);
            *(pp - (i - 3)*2 - 1) = (unsigned short)carry;
            *(pp - (i - 3)*2 - 2) = carry >> 16;
        }
    }
}
