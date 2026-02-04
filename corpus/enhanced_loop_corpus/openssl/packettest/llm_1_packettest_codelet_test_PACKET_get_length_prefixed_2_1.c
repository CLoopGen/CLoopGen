#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf1[1024];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= 256; i++) {
        buf1[i * 4 - 4] = (i * 8) & 255;
        buf1[i * 4 - 3] = ((i * 4 + 1) * 2) & 255;
        buf1[i * 4 - 2] = ((i * 4 + 2) * 2) & 255;
        buf1[i * 4 - 1] = ((i * 4 + 3) * 2) & 255;
    }
}
