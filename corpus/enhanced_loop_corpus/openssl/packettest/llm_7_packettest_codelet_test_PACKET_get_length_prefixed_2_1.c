#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf1[1024];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp[1024];
    unsigned int j;
    for (j = 0; j < 1024; j++) {
        temp[j] = ((j + 1) * 2) & 255;
    }
    for (j = 0; j < 1024; j++) {
        buf1[j] = temp[j];
    }
}
