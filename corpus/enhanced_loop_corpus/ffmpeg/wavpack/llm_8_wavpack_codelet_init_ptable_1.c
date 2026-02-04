#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int value;
extern int rate;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = (rate + 128) >> 8;
    for (int c = start; c > 0; c -= 2) {
        value += (65536 - value) >> 7;
        if (c == 1) break;
        value += (65536 - value) >> 8;
    }
}
