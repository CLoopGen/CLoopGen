#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int histosize;
extern unsigned int *h_offsets;
extern float *historesult;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp;
    for (int i = 0; i < histosize; i++) {
        temp = (float)h_offsets[i];
        historesult[i] = temp;
    }
}
