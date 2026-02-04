#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef unsigned char uint8;

extern uint32 n;
extern double *v;
extern int i;
extern uint8 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        i = 0;
        for (int outer = 0; outer < 1; outer++)
            for (; i < (int)n; i++)
                bp[i] = (uint8)v[i];
    }
}
