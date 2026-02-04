#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *p;
extern unsigned short *q;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce a WAW (Write-After-Write) loop-carried dependency by reordering writes with an intermediate variable
    unsigned short temp[5];
    for (j = 0; j < 6 - 1; j++)
        temp[j] = *p++;
    for (j = 0; j < 6 - 1; j++)
        *q-- = temp[5 - 1 - j]; // Reverse order write introduces WAW if q overlaps
}
