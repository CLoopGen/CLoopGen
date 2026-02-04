#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int top;
extern unsigned long *bdp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long offset = 1;
    for (i = 1; i < top; i += 2) { // Unroll by 2 to remove loop-carried dependency
        if (i < top) bdp[i] = 0;
        if (i + 1 < top) bdp[i + 1] = 0;
    }
}
