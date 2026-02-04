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
    if (n > 0) {
        i = 0;
        for (int chunk = 0; chunk < (int)n; chunk += 1) {
            bp[i] = (int16)v[i];
            i++;
        }
    }
}
