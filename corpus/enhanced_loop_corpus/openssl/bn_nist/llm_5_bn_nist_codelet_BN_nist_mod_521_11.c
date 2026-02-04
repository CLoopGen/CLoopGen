#include <stdio.h>

#include <inttypes.h>

extern unsigned long t_d[9];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; ii < (521 + (8 * 8) - 1) / (8 * 8); ii++) {
        (t_d)[ii] = 0;
        if (ii == 7) break;
    }
}
