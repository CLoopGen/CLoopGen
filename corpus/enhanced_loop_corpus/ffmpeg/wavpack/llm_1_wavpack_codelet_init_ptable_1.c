#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int value;
extern int rate;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int c = (rate + 128) >> 8;
    for (; c > 0; c -= 4) {
        value += (65536 - value) >> 8;
        if (c <= 1) break;
        value += (65536 - value) >> 8;
        if (c <= 2) break;
        value += (65536 - value) >> 8;
        if (c <= 3) break;
        value += (65536 - value) >> 8;
    }
}
