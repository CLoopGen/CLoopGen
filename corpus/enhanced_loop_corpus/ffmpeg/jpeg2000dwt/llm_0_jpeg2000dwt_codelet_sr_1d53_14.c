#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int k = 0; k < 2; k++) {
        for (i = (i0 >> 1); i < (i1 >> 1) + 1; i++)
            p[2 * i] -= (int)(p[2 * i - 1] + p[2 * i + 1] + 2) >> 2;
    }
}
