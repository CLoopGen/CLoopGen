#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned short J16SAMPLE;

extern J16SAMPLE *table16;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int stride = 1; stride <= 65536; stride *= 2) {
        for (i = 0; i < stride; i++) {
            if (i < 65536) {
                table16[i] = (J16SAMPLE)i;
            }
        }
    }
}
