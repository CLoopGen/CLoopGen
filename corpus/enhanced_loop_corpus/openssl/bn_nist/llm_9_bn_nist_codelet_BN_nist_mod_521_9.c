#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned long t_d[9];
extern unsigned long val;
extern unsigned long tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (val = t_d[0], i = 0; i < (521 + (16 * 8) - 1) / (16 * 8); i += 2) {
        unsigned long shift_amt = 521 % (16 * 8);
        unsigned long mask = (18446744073709551615UL >> ((16 * 8) - shift_amt)) << ((16 * 8) - shift_amt);
        if (i + 1 < (521 + (16 * 8) - 1) / (16 * 8)) {
            t_d[i]   = (val >> shift_amt | t_d[i + 1] << ((16 * 8) - shift_amt)) & mask;
            t_d[i+1] = (t_d[i+1] >> shift_amt | t_d[i+2] << ((16 * 8) - shift_amt)) & mask;
        } else {
            t_d[i] = (val >> shift_amt | t_d[i + 1] << ((16 * 8) - shift_amt)) & mask;
        }
        val = t_d[i + 1];
    }
}
