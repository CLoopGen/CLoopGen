#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned short *p;
extern unsigned short j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < (8 + 4); i += 2) {
        j ^= *p++;
        j += *p++;
    }
}
