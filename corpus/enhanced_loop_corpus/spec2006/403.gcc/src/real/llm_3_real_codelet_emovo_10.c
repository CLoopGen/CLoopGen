#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *p;
extern unsigned short *q;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process every second element by advancing pointers in steps of 2
    for (j = 0; j < (6 - 1) * 2; j += 2)
        *(q - j/2) = *(p + j/2);
}
