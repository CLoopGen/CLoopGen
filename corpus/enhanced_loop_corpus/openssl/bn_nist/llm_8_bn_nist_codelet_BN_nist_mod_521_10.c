#include <stdio.h>

#include <inttypes.h>

extern int top;
extern unsigned long t_d[9];
extern int ii;
extern  unsigned long *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (ii = 0; ii < top - ((521 + (8 * 8) - 1) / (8 * 8) - 1); ii += step) {
        if (ii + 1 < top - ((521 + (8 * 8) - 1) / (8 * 8) - 1)) {
            t_d[ii] = src[ii];
            t_d[ii + 1] = src[ii + 1];
        } else {
            t_d[ii] = src[ii];
        }
    }
}
