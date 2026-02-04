#include <stdio.h>

#include <inttypes.h>

extern unsigned char smbuf[256];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int j;
    for (j = 0; j < 255; j++) {
        smbuf[j] = ((j + 1) * 2) & 255;
    }
}
