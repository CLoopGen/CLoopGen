#include <stdio.h>

#include <inttypes.h>

extern unsigned int *d;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int indices[256];
    for (i = 0; i < 256; i++)
        indices[i] = 255 - i; // reverse index mapping
    for (i = 0; i < 256; i++)
        d[indices[i]] = indices[i];
}
