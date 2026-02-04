#include <stdio.h>

#include <inttypes.h>

extern unsigned long t;
extern unsigned long w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (w = 1; (w & t) != 0; w <<= 1)
    {
        continue;
    }
}
