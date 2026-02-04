#include <stdio.h>

#include <inttypes.h>

extern int top;
extern unsigned long t_d[9];
extern int ii;
extern  unsigned long *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long temp;
    for (ii = 0; ii < top - ((521 + (8 * 8) - 1) / (8 * 8) - 1); ii++) {
        temp = src[ii];
        t_d[ii] = temp;
    }
}
