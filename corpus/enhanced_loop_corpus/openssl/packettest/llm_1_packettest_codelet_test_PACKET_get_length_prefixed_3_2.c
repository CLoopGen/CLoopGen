#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf1[1024];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 256; i++) {
        for (int step = 0; step < 4; step++) {
            int index = i * 4 + step;
            if (index < 1024) {
                buf1[index] = (index * 2) & 255;
            }
        }
    }
}
