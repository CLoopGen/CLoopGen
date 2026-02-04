#include <stdio.h>

#include <inttypes.h>

extern long num[5];
extern int i;
extern unsigned long work;
extern unsigned long carry;
extern unsigned long scale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long local_carry = carry;
    for (i = 0; i <= 4 - 1; i++) {
        unsigned long local_work = (num[i] * scale) + local_carry;
        num[i] = ((local_work) & (((unsigned long)1 << ((8 * 8) / 2)) - 1));
        local_carry = ((unsigned long)(local_work) >> (8 * 8) / 2);
    }
    carry = local_carry;
}
