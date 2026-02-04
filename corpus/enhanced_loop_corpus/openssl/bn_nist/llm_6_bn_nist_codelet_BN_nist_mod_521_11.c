#include <stdio.h>

#include <inttypes.h>

extern unsigned long t_d[9];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp = 0;
    for (; ii < (521 + (8 * 8) - 1) / (8 * 8); ii++) {
        temp += t_d[ii];
        t_d[ii] = temp;
    }
}
