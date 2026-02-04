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
    for (i = (i0 >> 2); i < (i1 >> 2); i++) {
        p[4 * i + 1] += (int)(p[4 * i] + p[4 * i + 2]) >> 1;
        p[4 * i + 3] += (int)(p[4 * i + 2] + p[4 * i + 4]) >> 1;
    }
}
