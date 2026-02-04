#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned long t_d[9];
extern unsigned long val;
extern unsigned long tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    val = t_d[0];
    for (i = 0; i < (521 + (8 * 8) - 1) / (8 * 8) - 1; i++) {
        unsigned long temp_shift = (8 * 8) - (521 % (8 * 8));
        unsigned long shifted_in = t_d[i + 1] << temp_shift;
        unsigned long shifted_out = val >> (521 % (8 * 8));
        t_d[i] = (shifted_out | shifted_in) & (18446744073709551615UL);
        val = t_d[i + 1];
    }
}
