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
for (i = 3; i < 10; i++) {
    m = (unsigned int)aa * *ps;
    carry = (m & 65535) + *pp;
    *pp = (unsigned short)carry;
    carry = (carry >> 16) + (m >> 16);
    --ps;
    --pp;
    *pp = (unsigned short)carry;
    *(pp - 1) = carry >> 16;
    if (*(pp + 1) == 0) {
        *(pp - 2) = 0;
    }
}
}
