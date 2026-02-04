#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short J12SAMPLE;

extern J12SAMPLE *table12;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2048; i < 2 * (4095 + 1); i += 2) {
        table12[i] = 4095;
        if (i + 1 < 2 * (4095 + 1)) {
            table12[i + 1] = table12[i]; // Introduces RAW dependency: current iteration reads from previous write
        }
    }
}
