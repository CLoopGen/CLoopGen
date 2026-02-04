#include <stdio.h>

#include <inttypes.h>

extern unsigned char smbuf[256];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 255; i++) {
        smbuf[i] = ((i + 1) * 2) & 255;
    }
}
