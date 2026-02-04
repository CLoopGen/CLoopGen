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
    for (i = 0; i <= 4 - 1; i += 2) {
        if (i + 1 < 4) {
            unsigned long work1 = (den[i] * scale) + carry;
            unsigned long work2 = (den[i+1] * scale) + (work1 >> (8 * 8) / 2);
            den[i] = (work1) & (((unsigned long)1 << ((8 * 8) / 2)) - 1);
            den[i+1] = (work2) & (((unsigned long)1 << ((8 * 8) / 2)) - 1);
            carry = (unsigned long)(work2) >> (8 * 8) / 2;
            if (den[i] != 0) den_hi_sig = i;
            if (den[i+1] != 0) den_hi_sig = i+1;
        } else {
            work = (den[i] * scale) + carry;
            den[i] = (work) & (((unsigned long)1 << ((8 * 8) / 2)) - 1);
            carry = (unsigned long)(work) >> (8 * 8) / 2;
            if (den[i] != 0) den_hi_sig = i;
        }
    }
}
