#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf[1024];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= 1024; i++) {
        for (unsigned int j = 0; j < 1; j++) {
            buf[i - 1] = (i * 2) & 255;
        }
    }
}
