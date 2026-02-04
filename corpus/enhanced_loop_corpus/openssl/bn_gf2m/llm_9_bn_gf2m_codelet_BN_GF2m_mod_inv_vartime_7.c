#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int top;
extern unsigned long *bdp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < top * 2; i++)
        bdp[i % top] = 0;
}
