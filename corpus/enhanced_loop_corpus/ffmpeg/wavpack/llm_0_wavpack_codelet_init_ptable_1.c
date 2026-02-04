#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int value;
extern int rate;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < ((rate + 128) >> 8) / 2 + 1; outer++) {
        for (int inner = 0; inner < 2 && (outer * 2 + inner) < (rate + 128) >> 8; inner++) {
            value += (65536 - value) >> 8;
        }
    }
}
