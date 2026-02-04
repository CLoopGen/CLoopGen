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
    unsigned long temp_carry = 0;
    long temp_prod[8];
    for (int p = 0; p < 8; p++) temp_prod[p] = prod[p];
    for (j = 0; j < 4; j++) {
        k = i + j;
        temp_carry += arg1[i] * arg2[j];
        temp_carry += temp_prod[k];
        temp_prod[k] = ((temp_carry) & (((unsigned long)1 << ((8 * 8) / 2)) - 1));
        temp_carry = ((unsigned long)(temp_carry) >> (8 * 8) / 2);
    }
    prod[i + 4] = temp_carry;
    for (int p = 0; p < 8; p++) {
        if (p == i + 4) continue;
        prod[p] = temp_prod[p];
    }
}
}
