#include <stdio.h>

#include <inttypes.h>

extern unsigned int *d;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (unsigned int j = 0; j < 256; j += 4)
        for (i = j; i < j + 4 && i < 256; i++)
            d[i] = i;
}
