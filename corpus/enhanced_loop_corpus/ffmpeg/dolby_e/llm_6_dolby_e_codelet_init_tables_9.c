#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float mantissa_tab1[17][4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp[17];
    for (i = 1; i < 17; i++) {
        temp[i] = 1.F / (1 << i - 1);
        mantissa_tab1[i][0] = temp[i];
    }
}
