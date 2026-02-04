#include <stdio.h>

#include <inttypes.h>

extern unsigned int *d;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 512; i += 2) {
        d[i] = i;
        if (i + 1 < 512) {
            d[i + 1] = i + 1;
        }
    }
}
