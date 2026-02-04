#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned short local_x[5];
    for (i = 0; i < 6 - 1; i++)
        local_x[i] = 0;
    for (i = 0; i < 6 - 1; i++)
        *x++ = local_x[i];
}
