#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp1, temp2;
    for (i = 1; i <= 4; i++) {
        temp1 = p[i0 + i];
        temp2 = p[i1 - i - 1];
        p[i0 - i] = temp1;
        p[i1 + i - 1] = temp2;
    }
}
