#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short J12SAMPLE;

extern J12SAMPLE *table12;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 2; outer++) {
        for (i = 2048 + outer * 2048; i < 2048 + (outer + 1) * 2048 && i < 2 * (4095 + 1); i++)
            table12[i] = 4095;
    }
}
