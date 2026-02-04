#include <stdio.h>

#include <inttypes.h>

extern long num[5];
extern long quo[4];
extern int i;
extern unsigned long work;
extern unsigned long carry;
extern unsigned long lden;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 4 - 1; i >= 0; i--) {
        work = num[i] + carry * ((unsigned long)1 << (8 * 8) / 2);
        if (lden != 0) {
            quo[i] = work / lden;
            carry = work % lden;
        } else {
            quo[i] = 0;
            carry = 0;
        }
    }
}
