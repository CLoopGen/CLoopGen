#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf[1024];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp[1024];
    unsigned int j;
    for (j = 0; j < 1024; j++) {
        temp[j] = ((j + 1) * 2) & 255;
    }
    for (j = 0; j < 1024; j++) {
        buf[j] = temp[j];
    }
}
