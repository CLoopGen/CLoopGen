#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int max_sfac[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i += 2)
    {
        max_sfac[i] = 0;
        if (i + 1 < 4) max_sfac[i + 1] = 0;
    }
}
