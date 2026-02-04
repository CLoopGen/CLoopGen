#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf1[1024];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 1024; i += 4) {
        buf1[i] = (i * 2) & 255;
        if (i + 1 < 1024) buf1[i + 1] = ((i + 1) * 2) & 255;
        if (i + 2 < 1024) buf1[i + 2] = ((i + 2) * 2) & 255;
        if (i + 3 < 1024) buf1[i + 3] = ((i + 3) * 2) & 255;
    }
}
