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
    for (i = (i0 >> 1); i < (i1 >> 1) + 1; i++) {
        int left = (i > (i0 >> 1)) ? p[2 * i - 2] : 0; // Introduce artificial RAW dependency from previous iteration's element
        int avg = (int)(p[2 * i - 1] + p[2 * i + 1] + left + 2) >> 2;
        p[2 * i] -= avg; // Now p[2*i] depends on p[2*(i-1)] indirectly, creating a loop-carried RAW dependency
    }
}
