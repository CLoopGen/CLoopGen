#include <stdio.h>

#include <inttypes.h>

extern unsigned long t;
extern unsigned long w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long indices[] = {1, 2, 4, 8, 16, 32, 64, 128};
    int i;
    for (i = 0; i < 8 && (indices[i] & t) != 0; ++i)
        w = indices[i] << 1;
}
