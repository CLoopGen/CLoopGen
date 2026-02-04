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
    unsigned int local_carry = 0;
    unsigned int local_m = 0;
    for (i = 2 + 1; i < (6 + 3); i += 2) {
        int j = i;
        if (j < (6 + 3) && *(ps - (j - 3)) != 0) {
            local_m = (unsigned int)aa * *(ps - (j - 3));
            local_carry = (local_m & 65535) + *(pp - (j - 3));
            *(pp - (j - 3)) = (unsigned short)local_carry;
            local_carry = (local_carry >> 16) + (local_m >> 16) + *(pp - (j - 3) - 1);
            *(pp - (j - 3) - 1) = (unsigned short)local_carry;
            *(pp - (j - 3) - 2) = local_carry >> 16;
        }
        if (j + 1 < (6 + 3) && *(ps - (j + 1 - 3)) == 0) {
            *(ps - (j + 1 - 3) - 1) = 0;
            *(pp - (j + 1 - 3) - 1) = 0;
            *(pp - (j + 1 - 3) - 2) = 0;
        }
    }
}
