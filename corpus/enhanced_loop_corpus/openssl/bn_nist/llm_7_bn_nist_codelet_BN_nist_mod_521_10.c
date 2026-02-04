#include <stdio.h>

#include <inttypes.h>

extern int top;
extern unsigned long t_d[9];
extern int ii;
extern  unsigned long *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 1; ii < top - ((521 + (8 * 8) - 1) / (8 * 8) - 1); ii++) {
        t_d[ii] = src[ii-1];
    }
    if (top - ((521 + (8 * 8) - 1) / (8 * 8) - 1) > 0) {
        t_d[0] = src[0];
    }
}
