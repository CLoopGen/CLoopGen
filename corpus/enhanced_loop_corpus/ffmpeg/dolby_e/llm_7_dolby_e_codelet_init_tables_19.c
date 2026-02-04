#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp[128];
    for (i = 0; i < 128; i++) {
        temp[i] = window[i];
    }
    for (i = 0; i < 128; i++) {
        window[960 + i] = temp[i];
    }
}
