#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned short J16SAMPLE;

extern J16SAMPLE *table16;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 32767; i++) {
        table16[2*i] = (J16SAMPLE)(2*i);
        table16[2*i + 1] = (J16SAMPLE)(2*i + 1);
    }
}
