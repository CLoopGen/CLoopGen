#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf1[1024];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int indices[1024];
    for (i = 0; i < 1024; i++) {
        indices[i] = 1023 - i; // reverse access pattern
    }
    for (i = 0; i < 1024; i++) {
        unsigned int j = indices[i];
        buf1[j] = (j * 2) & 255;
    }
}
