#include <stdio.h>

#include <inttypes.h>

extern long den[4];
extern int i;
extern unsigned long work;
extern unsigned long carry;
extern int den_hi_sig;
extern unsigned long scale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= 4 - 1; i++) {
    work = (den[i] * scale) + carry;
    den[i] = ((work) & (((unsigned long)1 << ((8 * 8) / 2)) - 1));
    carry = ((unsigned long)(work) >> (8 * 8) / 2);
    if (den[i] == 0)
        continue;
    den_hi_sig = i;
}
}
