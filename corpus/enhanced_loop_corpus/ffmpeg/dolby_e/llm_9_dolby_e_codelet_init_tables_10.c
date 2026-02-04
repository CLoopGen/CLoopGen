#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float mantissa_tab1[17][4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 4; i < 12; i++) {
    float base = (1 << i) - 1;
    mantissa_tab1[i][1] = 1.F / base;
    mantissa_tab1[i][2] = 0.5F / base;
    mantissa_tab1[i][3] = 0.25F / base;
    mantissa_tab1[i][0] = 2.0F / base;
    mantissa_tab1[15 - i][1] = 0.75F / base;
    mantissa_tab1[15 - i][2] = 0.125F / base;
}
}
