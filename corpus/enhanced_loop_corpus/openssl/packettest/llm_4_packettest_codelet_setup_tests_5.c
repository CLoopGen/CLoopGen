#include <stdio.h>

#include <inttypes.h>

extern unsigned char smbuf[256];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= 255; i++) {
        if (i % 2 == 0)
            smbuf[i - 1] = (i * 2) & 255;
        else
            smbuf[i - 1] = 0;
    }
}
