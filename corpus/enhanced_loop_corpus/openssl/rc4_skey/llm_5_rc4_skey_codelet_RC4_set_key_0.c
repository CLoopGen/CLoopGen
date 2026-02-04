#include <stdio.h>

#include <inttypes.h>

extern unsigned int *d;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 256; i++) {
        if (i < 128)
            d[i] = i;
        else
            d[i] = 0;
    }
}
