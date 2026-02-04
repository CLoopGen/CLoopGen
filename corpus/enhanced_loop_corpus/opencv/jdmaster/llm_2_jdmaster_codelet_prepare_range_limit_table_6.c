#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned short J16SAMPLE;

extern J16SAMPLE *table16;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 4
    for (i = 0; i <= 65535; i += 4) {
        table16[i] = (J16SAMPLE)i;
        if (i + 1 <= 65535) table16[i + 1] = (J16SAMPLE)(i + 1);
        if (i + 2 <= 65535) table16[i + 2] = (J16SAMPLE)(i + 2);
        if (i + 3 <= 65535) table16[i + 3] = (J16SAMPLE)(i + 3);
    }
}
