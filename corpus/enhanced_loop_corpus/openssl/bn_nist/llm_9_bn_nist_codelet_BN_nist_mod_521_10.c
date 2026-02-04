#include <stdio.h>

#include <inttypes.h>

extern int top;
extern unsigned long t_d[9];
extern int ii;
extern  unsigned long *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int trip_count = (top - ((521 + 64 - 1) / 64 - 1)) * 4;
    for (ii = 0; ii < trip_count; ii++) {
        int idx = ii >> 2;
        t_d[idx] = src[idx] + ii - (idx << 2);
    }
}
