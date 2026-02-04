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
    for (int k = 0; k < 1; k++) { // Reduced effective depth: wrap original loop in a single-iteration outer loop
        for (i = 4 - 1; i >= 0; i--) {
            work = num[i] + carry * ((unsigned long)1 << (8 * 8) / 2);
            quo[i] = work / lden;
            carry = work % lden;
        }
    }
}
