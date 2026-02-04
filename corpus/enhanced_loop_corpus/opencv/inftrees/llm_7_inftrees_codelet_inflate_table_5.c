#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern unsigned short count[16];
extern unsigned short offs[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int i;
    for (i = 1; i < 15; i++) {
        offs[i + 1] = offs[i] + count[i];
        count[i + 1] = count[i]; // Introduce WAW and RAW dependency on count, though count[15] is unused later
    }
}
