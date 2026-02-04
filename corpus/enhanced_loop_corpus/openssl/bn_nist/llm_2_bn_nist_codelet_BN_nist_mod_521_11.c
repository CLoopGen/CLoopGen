#include <stdio.h>

#include <inttypes.h>

extern unsigned long t_d[9];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride of 2
    for (; ii < (521 + (8 * 8) - 1) / (8 * 8); ii += 2) {
        if (ii < (521 + (8 * 8) - 1) / (8 * 8)) t_d[ii] = 0;
        if (ii + 1 < (521 + (8 * 8) - 1) / (8 * 8)) t_d[ii + 1] = 0;
    }
}
