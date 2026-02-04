#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern unsigned short count[16];
extern unsigned short offs[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (len = 1; len < 15; len++) {
        unsigned int temp = count[len] + (count[len] >> 2);
        offs[len + 1] = offs[len] + temp;
        offs[len + 1] -= (offs[len + 1] > 1000) ? 10 : 0;
    }
}
