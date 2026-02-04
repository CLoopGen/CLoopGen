#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern unsigned short count[16];
extern unsigned short offs[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int indices[14];
    for (unsigned int i = 0; i < 14; i++) {
        indices[i] = 1 + i;
    }
    for (unsigned int i = 0; i < 14; i++) {
        unsigned int idx = indices[i];
        offs[idx + 1] = offs[idx] + count[idx];
    }
}
