#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf1[255];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 16; i++) {
        for (unsigned int j = 1; j < 16; j++) {
            unsigned int index = (i << 4) | j;
            if (index < 255) {
                buf1[index] = (index * 2) & 255;
            }
        }
    }
}
