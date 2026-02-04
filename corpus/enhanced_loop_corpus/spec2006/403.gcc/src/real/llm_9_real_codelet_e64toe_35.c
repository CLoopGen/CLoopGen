#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *e;
extern unsigned short *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        unsigned short val1 = *e++;
        unsigned short val2 = *e++;
        *p-- = val2;
        *p-- = val1;
        *p-- = *e++;
        *p-- = *e++;
    }
}
