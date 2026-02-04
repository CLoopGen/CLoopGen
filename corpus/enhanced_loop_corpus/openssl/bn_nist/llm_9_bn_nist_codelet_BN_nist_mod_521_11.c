#include <stdio.h>

#include <inttypes.h>

extern unsigned long t_d[9];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; ii < (521 + 8*8 - 1) / (8*8); ii += 2) { // Increase step size, reduce trip count
        t_d[ii] = 0;
        if (ii + 1 < (521 + 64 - 1) / 64) {
            t_d[ii + 1] = 0; // Unroll one extra iteration manually
        }
    }
}
