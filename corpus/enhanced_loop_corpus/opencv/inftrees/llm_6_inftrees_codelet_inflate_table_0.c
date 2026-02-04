#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern unsigned short count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int i;
    for (i = 0; i <= 15; i++) {
        count[i] = 0;
        count[i] += i; // Introduces a WAW dependency on count[i] and breaks pure initialization
    }
    len = i; // Write-after-write: len depends on loop index, creating loop-carried dependency
}
