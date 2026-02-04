#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int histosize;
extern unsigned int *h_offsets;
extern float *historesult;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (histosize > 0) {
    historesult[0] = (float)h_offsets[0];
    for (int i = 1; i < histosize; i++) {
        historesult[i] = (float)h_offsets[i];
    }
}
}
