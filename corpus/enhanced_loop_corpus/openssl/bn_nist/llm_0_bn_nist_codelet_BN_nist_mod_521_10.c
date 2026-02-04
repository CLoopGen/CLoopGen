#include <stdio.h>

#include <inttypes.h>

extern int top;
extern unsigned long t_d[9];
extern int ii;
extern  unsigned long *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int jj;
    for (jj = 0; jj < 2; jj++)
        for (ii = 0; ii < top - ((521 + (8 * 8) - 1) / (8 * 8) - 1); ii++)
            (t_d)[ii] = src[ii];
}
