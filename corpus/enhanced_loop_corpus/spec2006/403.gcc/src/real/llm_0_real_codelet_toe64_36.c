#include <stdio.h>

#include <inttypes.h>

extern unsigned short *p;
extern unsigned short *q;
extern unsigned short i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned short j;
    for (j = 0; j < 1; j++)
        for (i = 0; i < 4; i++)
            *q++ = *p++;
}
