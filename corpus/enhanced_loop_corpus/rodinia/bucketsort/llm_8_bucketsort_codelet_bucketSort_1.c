#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int histosize;
extern unsigned int *h_offsets;
extern float *historesult;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < histosize; i += 2) {
        if (i + 1 < histosize) {
            historesult[i] = (float)(h_offsets[i] + h_offsets[i + 1]) * 0.5f;
            historesult[i + 1] = (float)(h_offsets[i + 1] - h_offsets[i]) * 0.5f;
        } else {
            historesult[i] = (float)h_offsets[i];
        }
    }
}
