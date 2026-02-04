#include <stdio.h>

#include <inttypes.h>

extern int top;
extern unsigned long t_d[9];
extern int ii;
extern  unsigned long *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < top - ((521 + (8 * 8) - 1) / (8 * 8) - 1); ii++) {
        int inner_limit = (top - ((521 + (8 * 8) - 1) / (8 * 8) - 1) > ii + 1) ? 1 : 0;
        for (int kk = 0; kk <= inner_limit; kk++)
            (t_d)[ii] = src[ii];
    }
}
