#include <stdio.h>

#include <inttypes.h>

extern long num[5];
extern int i;
extern unsigned long work;
extern unsigned long carry;
extern unsigned long scale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 4 - 1; i++) {
        work = (num[i] * scale) + carry;
        if (work != 0) {
            num[i] = ((work) & (((unsigned long)1 << ((8 * 8) / 2)) - 1));
            carry = ((unsigned long)(work) >> (8 * 8) / 2);
        }
    }
}
