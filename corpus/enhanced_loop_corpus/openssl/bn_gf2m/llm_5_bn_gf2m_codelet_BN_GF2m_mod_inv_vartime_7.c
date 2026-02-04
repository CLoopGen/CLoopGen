#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int top;
extern unsigned long *bdp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < top && bdp[i] != 0; i++) {
        bdp[i] = 0;
    }
}
