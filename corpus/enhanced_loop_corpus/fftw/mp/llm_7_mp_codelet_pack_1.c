#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned short *d;
extern int e;
extern int l;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned short prev = 0;
    for (i = l - 1; i >= 0; --i, --e) {
        unsigned short curr = d[i];
        if (curr != 0 && prev == 0)  // Introduce loop-carried dependency via 'prev'
            break;
        prev = curr;  // Create loop-carried dependence (WAW and RAW) on 'prev'
    }
}
