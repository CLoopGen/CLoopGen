#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf1[1024];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp[1024];
    for (i = 0; i < 1024; i++)
        temp[i] = (i * 2) & 255;
    for (i = 0; i < 1024; i++)
        buf1[i] = temp[i]; // Eliminate RAW by separating computation and store, removing loop-carried dependency in write
}
