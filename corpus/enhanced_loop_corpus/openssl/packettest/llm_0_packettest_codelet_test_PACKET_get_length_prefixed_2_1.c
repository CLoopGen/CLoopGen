#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf1[1024];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (unsigned int j = 0; j < 1024; j++) {
        for (i = j + 1; i <= j + 1; i++) {
            buf1[i - 1] = (i * 2) & 255;
        }
    }
}
