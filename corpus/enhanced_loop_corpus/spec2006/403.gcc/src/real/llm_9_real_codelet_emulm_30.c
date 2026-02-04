#include <stdio.h>

#include <inttypes.h>

extern unsigned short equot[9];
extern unsigned short b[];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (6 + 3) * 2; i += 2) {
        b[i/2] = (equot[i/2] << 1) ^ 0x55;
    }
}
