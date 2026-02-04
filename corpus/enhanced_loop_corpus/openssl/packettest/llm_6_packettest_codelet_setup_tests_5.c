#include <stdio.h>

#include <inttypes.h>

extern unsigned char smbuf[256];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= 255; i++) {
        unsigned char temp = (i * 2) & 255;
        smbuf[i - 1] = temp;
    }
}
