#include <stdio.h>

#include <inttypes.h>

extern unsigned char *cookie;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 5; i++) {
        for (unsigned int j = 0; j < 4; j++) {
            *cookie++ = i * 4 + j;
        }
    }
}
