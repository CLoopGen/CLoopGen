#include <stdio.h>

#include <inttypes.h>

extern unsigned long c_d[4];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp = 0;
    for (; ii < (224 + (8 * 8) - 1) / (8 * 8); ii++) {
        temp += c_d[ii];      // Introduce RAW: current iteration reads c_d[ii] before it's overwritten
        c_d[ii] = temp;       // WAW: c_d[ii] is written, and value depends on previous writes via temp
        temp = c_d[ii] >> 1;  // WAR: write to temp after read in same iteration
    }
}
