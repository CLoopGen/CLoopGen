#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 128; i++) {
    float temp1 = window[703 - i];
    float temp2 = window[702 - i];
    float temp3 = window[701 - i];
    float temp4 = window[700 - i];
    window[2752 + i*4 + 0] = temp1;
    window[2752 + i*4 + 1] = temp2;
    window[2752 + i*4 + 2] = temp3;
    window[2752 + i*4 + 3] = temp4;
}
}
