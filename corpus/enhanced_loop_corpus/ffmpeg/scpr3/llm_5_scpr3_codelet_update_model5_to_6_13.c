#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int d;
extern int e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (e = 0; d <= 2048; e++) {
        if (d < 128) {
            d <<= 1;
        } else {
            d <<= 2;
            e++;
        }
        if (d > 1024) break;
    }
}
