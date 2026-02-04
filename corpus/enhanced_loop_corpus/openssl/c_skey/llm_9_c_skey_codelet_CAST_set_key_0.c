#include <stdio.h>

#include <inttypes.h>

extern unsigned int x[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i++) {
        unsigned int temp = i * i + 3U * i + 1U;
        if (i < 16) x[i] = temp ^ x[i];
    }
}
