#include <stdio.h>

#include <inttypes.h>

extern long num[5];
extern int i;
extern unsigned long work;
extern unsigned long carry;
extern unsigned long scale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 6 - 1; i++) {
        work = (num[i % 5] * (scale + i)) + carry + (i * 7);
        num[i % 5] = work & (((unsigned long)1 << 32) - 1);
        carry = (unsigned long)(work) >> 32;
    }
}
