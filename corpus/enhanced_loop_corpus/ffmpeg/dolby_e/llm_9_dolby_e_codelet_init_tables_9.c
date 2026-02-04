#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float mantissa_tab1[17][4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 32; i++) {
        if (i < 17) {
            mantissa_tab1[i][0] = 1.F / (1 << (i - 1));
        } else {
            mantissa_tab1[i % 17][1] = (float)(i * i);
        }
    }
}
