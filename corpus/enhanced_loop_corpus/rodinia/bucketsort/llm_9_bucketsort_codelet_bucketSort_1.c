#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int histosize;
extern unsigned int *h_offsets;
extern float *historesult;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < histosize * 2; i++) {
        int idx = i / 2;
        if (i % 2 == 0) {
            historesult[idx] = (float)h_offsets[idx];
        } else {
            historesult[idx] += (float)h_offsets[idx] * 0.1f;
        }
    }
}
