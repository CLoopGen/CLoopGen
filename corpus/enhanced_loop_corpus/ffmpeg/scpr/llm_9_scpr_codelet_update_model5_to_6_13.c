#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int d;
extern int e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (e = 0; d <= 8192; e += 2) {
        d <<= 1;
        if (d > 2048) break;
        d += (d << 1) >> 2;
    }
}
