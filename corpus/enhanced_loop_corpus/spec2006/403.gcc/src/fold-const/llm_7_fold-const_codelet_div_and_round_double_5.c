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
    unsigned long local_den[4];
    unsigned long temp_carry = 0;
    int local_den_hi_sig = -1;

    for (i = 0; i <= 4 - 1; i++) {
        work = (den[i] * scale) + temp_carry;
        local_den[i] = ((work) & (((unsigned long)1 << ((8 * 8) / 2)) - 1));
        temp_carry = ((unsigned long)(work) >> (8 * 8) / 2);
        if (local_den[i] != 0)
            local_den_hi_sig = i;
    }

    for (i = 0; i <= 4 - 1; i++) {
        den[i] = local_den[i];
    }
    carry = temp_carry;
    if (local_den_hi_sig != -1)
        den_hi_sig = local_den_hi_sig;
}
