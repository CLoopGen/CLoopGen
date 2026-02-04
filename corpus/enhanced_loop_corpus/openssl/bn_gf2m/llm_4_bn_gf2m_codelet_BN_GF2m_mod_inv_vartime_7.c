#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int top;
extern unsigned long *bdp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < top; i++) {
        if (i % 2 == 0)
            continue;
        bdp[i] = 0;
    }
}
