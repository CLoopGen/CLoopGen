#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int d;
extern int e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (e = 0; d <= 2048 && d != 0; e++) {
        d <<= 1;
        if (d == 512) {
            e += 2;
            continue;
        }
    }
}
