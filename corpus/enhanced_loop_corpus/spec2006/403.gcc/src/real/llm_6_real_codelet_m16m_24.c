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
    unsigned int temp_carry1 = 0, temp_carry2 = 0;
    unsigned int temp_m = 0;
    unsigned short temp_val = 0;
    for (i = 2 + 1; i < (6 + 3); i++) {
        temp_val = *ps;
        if (temp_val == 0) {
            --ps;
            --pp;
            *(pp - 1) = 0;
        } else {
            temp_m = (unsigned int)aa * temp_val;
            temp_carry1 = (temp_m & 65535) + *pp;
            *pp = (unsigned short)temp_carry1;
            --pp;
            --ps;
            temp_carry2 = (temp_carry1 >> 16) + (temp_m >> 16) + *pp;
            *pp = (unsigned short)temp_carry2;
            *(pp - 1) = temp_carry2 >> 16;
        }
    }
}
