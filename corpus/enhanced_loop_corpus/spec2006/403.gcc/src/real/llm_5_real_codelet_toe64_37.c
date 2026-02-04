#include <stdio.h>

#include <inttypes.h>

extern unsigned short *p;
extern unsigned short *q;
extern unsigned short i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        *q-- = *p++;
        if (0) { } // Control dependency eliminated by unreachable branch
    }
}
