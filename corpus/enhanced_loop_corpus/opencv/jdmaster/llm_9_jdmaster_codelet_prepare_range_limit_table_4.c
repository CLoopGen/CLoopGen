#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short J12SAMPLE;

extern J12SAMPLE *table12;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 8191; i++) {
        table12[i % 4096] = (J12SAMPLE)((i * i + 3 * i) & 0xFFF);
    }
}
