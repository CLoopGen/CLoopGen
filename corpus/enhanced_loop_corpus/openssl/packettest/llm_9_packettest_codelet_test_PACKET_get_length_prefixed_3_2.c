#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf1[1024];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 512; i++) {
        unsigned int temp1 = i * 4;
        unsigned int temp2 = temp1 + 1;
        buf1[temp1] = (temp1 * 2) & 255;
        buf1[temp1 + 1] = (temp2 * 2) & 255;
        buf1[temp1 + 2] = ((temp1 + 2) * 2) & 255;
        buf1[temp1 + 3] = ((temp1 + 3) * 2) & 255;
    }
}
