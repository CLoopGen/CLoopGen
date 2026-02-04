#include <stdio.h>

#include <inttypes.h>

extern unsigned char smbuf[256];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= 255; i++) {
        smbuf[i - 1] = 0;
        if (i > 32 && i <= 224)
            smbuf[i - 1] = (i * 2) & 255;
    }
}
