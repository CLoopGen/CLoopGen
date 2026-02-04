#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *e;
extern unsigned short *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i += 2) {
        *p-- = *e++;
        *p-- = *e++;
    }
}
