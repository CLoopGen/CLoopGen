#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned short J16SAMPLE;

extern J16SAMPLE *table16;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    J16SAMPLE prev = 0;
    for (i = 0; i <= 65535; i++) {
        table16[i] = (J16SAMPLE)(i + prev);
        prev = table16[i];
    }
}
