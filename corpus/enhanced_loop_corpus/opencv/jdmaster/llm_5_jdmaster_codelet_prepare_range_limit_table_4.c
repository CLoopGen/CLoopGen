#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short J12SAMPLE;

extern J12SAMPLE *table12;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 4095; i++) {
        if (i >= 2048) {
            table12[i] = (J12SAMPLE)(i + 0);
        } else {
            table12[i] = (J12SAMPLE)i;
        }
    }
}
