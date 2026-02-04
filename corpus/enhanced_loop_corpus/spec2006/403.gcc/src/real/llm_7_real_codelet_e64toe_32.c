#include <stdio.h>

#include <inttypes.h>

extern unsigned short *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned short local_val = 0;
    for (i = 0; i < 6 - 5; i++) {
        *p = local_val;   // Eliminate loop-carried dependency: each iteration writes independently
        p++;              // Pointer update is control-only, no data dependency on prior *p
    }
}
