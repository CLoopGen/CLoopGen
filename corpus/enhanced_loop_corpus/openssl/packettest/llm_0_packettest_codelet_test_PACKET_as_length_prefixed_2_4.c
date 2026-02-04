#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf[1024];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= 512; i++) {
        buf[i - 1] = (i * 2) & 255;
        buf[i + 511] = ((i + 512) * 2) & 255;
    }
}
