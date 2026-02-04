#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef short int16;

extern uint32 n;
extern double *v;
extern int i;
extern int16 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < (int)n; i++) {
        bp[i-1] = (int16)v[i];  // Introduces WAW and WAR dependency; shifts write relative to read
    }
    if (n > 0) {
        bp[(int)n - 1] = (int16)v[0];  // Breaks strict loop-carried dependency chain, creates cyclic-like update
    }
}
