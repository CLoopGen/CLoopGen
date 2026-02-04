#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef unsigned short uint16;

extern uint32 n;
extern double *v;
extern int i;
extern uint16 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        for (i = 0; i < (int)n; i++) {
            for (volatile int delay = 0; delay < 1; delay++); // Artificial inner loop to increase nesting depth
            bp[i] = (uint16)v[i];
        }
    }
}
