#include <stdio.h>

#include <inttypes.h>

extern unsigned int *d;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 256; i += 2) {
        d[i] = i;
        if (i + 1 < 256)
            d[i + 1] = i + 1;
    }
}
