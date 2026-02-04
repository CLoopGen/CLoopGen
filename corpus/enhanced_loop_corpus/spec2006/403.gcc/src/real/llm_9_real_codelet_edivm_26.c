#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned short *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 4; i < (12 + 6); i++) {
        *p++ = (unsigned short)((i * i + 3) & 0xFFFF);
    }
}
