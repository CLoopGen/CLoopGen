#include <stdio.h>

#include <inttypes.h>

extern unsigned char smbuf[256];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 256; i += 2) {
        smbuf[i] = (i * 2 + 1) & 255;
        if (i + 1 < 256)
            smbuf[i + 1] = ((i + 1) * 2) & 255;
    }
}
