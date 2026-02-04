#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned short J16SAMPLE;

extern J16SAMPLE *table16;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 256; outer++) {
        for (int inner = 0; inner < 256; inner++) {
            int index = (outer << 8) | inner;
            table16[index] = (J16SAMPLE)index;
        }
    }
}
