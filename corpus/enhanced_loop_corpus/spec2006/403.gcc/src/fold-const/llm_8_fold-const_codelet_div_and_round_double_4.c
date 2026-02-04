#include <stdio.h>

#include <inttypes.h>

extern long num[5];
extern int i;
extern unsigned long work;
extern unsigned long carry;
extern unsigned long scale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 4 - 1; i += 2) {
        if (i + 1 <= 4 - 1) {
            work = (num[i] * scale) + carry;
            num[i] = work & (((unsigned long)1 << (32)) - 1);
            carry = (unsigned long)(work) >> 32;

            work = (num[i+1] * scale) + carry;
            num[i+1] = work & (((unsigned long)1 << (32)) - 1);
            carry = (unsigned long)(work) >> 32;
        } else {
            work = (num[i] * scale) + carry;
            num[i] = work & (((unsigned long)1 << (32)) - 1);
            carry = (unsigned long)(work) >> 32;
        }
    }
}
