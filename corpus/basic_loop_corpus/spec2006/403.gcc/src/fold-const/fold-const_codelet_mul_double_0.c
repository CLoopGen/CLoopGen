#include <stdio.h>

#include <inttypes.h>

extern long arg1[4];
extern long arg2[4];
extern long prod[8];
extern unsigned long carry;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 4; i++) {
    carry = 0;
    for (j = 0; j < 4; j++) {
        k = i + j;
        carry += arg1[i] * arg2[j];
        carry += prod[k];
        prod[k] = ((carry) & (((unsigned long)1 << ((8 * 8) / 2)) - 1));
        carry = ((unsigned long)(carry) >> (8 * 8) / 2);
    }
    prod[i + 4] = carry;
}

}
