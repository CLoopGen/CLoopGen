#include <stdio.h>

#include <inttypes.h>

extern unsigned char smbuf[256];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= 127; i++) {
        uint32_t temp1 = i * 3 + 1;
        uint32_t temp2 = (temp1 ^ (temp1 >> 2)) & 255;
        smbuf[i*2 - 2] = temp2;
        smbuf[i*2 - 1] = (temp2 >> 4) | (temp2 << 4);
    }
}
