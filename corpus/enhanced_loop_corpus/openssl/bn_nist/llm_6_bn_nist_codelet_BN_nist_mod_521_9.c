#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned long t_d[9];
extern unsigned long val;
extern unsigned long tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (val = t_d[0], i = 0; i < (521 + (8 * 8) - 1) / (8 * 8) - 1; i++) {
        unsigned long next_val = t_d[i + 1];
        t_d[i] = (val >> (521 % (8 * 8)) | next_val << ((8 * 8) - (521 % (8 * 8)))) & (18446744073709551615UL);
        val = next_val;
    }
}
