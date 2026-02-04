#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short J12SAMPLE;

extern J12SAMPLE *table12;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    J12SAMPLE temp = 0;
    for (i = 0; i <= 4095; i++) {
        temp = (J12SAMPLE)i;
        table12[i] = temp;
    }
}
