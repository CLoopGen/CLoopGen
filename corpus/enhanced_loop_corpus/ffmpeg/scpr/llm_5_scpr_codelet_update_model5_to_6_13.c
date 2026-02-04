#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int d;
extern int e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (e = 0; d <= 2048 && e < 32; e++) {
        d <<= 1;
        if (d > 1024) continue;
        e += 2;
    }
}
