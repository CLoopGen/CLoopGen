#include <stdio.h>

#include <inttypes.h>

extern unsigned int *d;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (unsigned int j = 0; j < 16; j++)
        for (i = j * 16; i < (j + 1) * 16; i++)
            d[i] = i;
}
