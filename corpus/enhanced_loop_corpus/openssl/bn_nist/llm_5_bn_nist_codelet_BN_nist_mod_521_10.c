#include <stdio.h>

#include <inttypes.h>

extern int top;
extern unsigned long t_d[9];
extern int ii;
extern  unsigned long *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = top - ((521 + 64 - 1) / 64 - 1);
    for (ii = 0; ii < limit; ii++) {
        if (ii % 2 == 0) {
            t_d[ii] = src[ii];
        } else {
            t_d[ii] = 0;
        }
    }
}
