#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf[1024];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int indices[1024];
    for (i = 0; i < 1024; i++)
        indices[i] = 1023 - i;
    for (i = 0; i < 1024; i++) {
        unsigned int idx = indices[i];
        buf[idx] = ((idx + 1) * 2) & 255;
    }
}
