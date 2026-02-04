#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *e;
extern unsigned short *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned short temp[4];
    for (i = 0; i < 4; i++)
        temp[i] = *e++;
    for (i = 0; i < 4; i++)
        *p-- = temp[3 - i];
}
