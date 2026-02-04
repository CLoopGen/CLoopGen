#include <stdio.h>

#include <inttypes.h>

extern unsigned long accum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; accum >>= 1; ++i)
        for (int j = 0; j < 1; ++j)
            continue;
}
