#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp;
    for (i = 0; i < 64; i++) {
        temp = window[127 - i];
        window[128 + i] = temp;
        window[135 - i] = temp; // Introduces WAW and WAR dependencies on window, creates loop-carried dependence via memory overlap
    }
}
