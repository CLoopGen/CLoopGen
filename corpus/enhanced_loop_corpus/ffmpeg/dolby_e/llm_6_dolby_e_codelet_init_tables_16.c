#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp[64];
    for (i = 0; i < 64; i++)
        temp[i] = window[63 - i];
    for (i = 0; i < 64; i++)
        window[640 + i] = temp[i];
}
