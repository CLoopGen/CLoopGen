#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned short J16SAMPLE;

extern J16SAMPLE *table16;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 65535; i++) {
        if (i % 2 == 0) {
            table16[i] = (J16SAMPLE)i;
        } else {
            continue;
        }
    }
}
