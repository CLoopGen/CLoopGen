#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf1[255];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 255; i++) {
        for (unsigned int j = 0; j < 1; j++) {
            buf1[i] = (i * 2) & 255;
        }
    }
}
