#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf1[255];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 255; i++) {
        if (i % 2 == 0)
            buf1[i] = (i * 2) & 255;
        else
            buf1[i] = 0;
    }
}
