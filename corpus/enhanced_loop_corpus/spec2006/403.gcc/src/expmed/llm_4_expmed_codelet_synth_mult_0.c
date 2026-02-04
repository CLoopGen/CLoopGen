#include <stdio.h>

#include <inttypes.h>

extern unsigned long t;
extern unsigned long w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (w = 1; (w & t) != 0; )
    {
        if ((w & t) == 0) break;
        w <<= 1;
    }
}
