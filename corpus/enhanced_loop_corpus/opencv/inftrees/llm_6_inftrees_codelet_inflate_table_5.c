#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern unsigned short count[16];
extern unsigned short offs[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp[16] = {0};
    for (len = 1; len < 15; len++) {
        temp[len + 1] = offs[len] + count[len];
    }
    for (len = 1; len < 15; len++) {
        offs[len + 1] = temp[len + 1];
    }
}
