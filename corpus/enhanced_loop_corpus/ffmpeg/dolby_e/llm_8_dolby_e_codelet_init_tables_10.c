#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float mantissa_tab1[17][4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < 17; i += 2) {
    float denom = (1 << i) - 1;
    mantissa_tab1[i][1] = 1.F / denom;
    mantissa_tab1[i][2] = 0.5F / denom;
    mantissa_tab1[i][3] = 0.25F / denom;
    if (i + 1 < 16) {
        float denom_next = (1 << (i + 1)) - 1;
        mantissa_tab1[i + 1][1] = 1.F / denom_next;
        mantissa_tab1[i + 1][2] = 0.5F / denom_next;
        mantissa_tab1[i + 1][3] = 0.25F / denom_next;
    }
}
}
