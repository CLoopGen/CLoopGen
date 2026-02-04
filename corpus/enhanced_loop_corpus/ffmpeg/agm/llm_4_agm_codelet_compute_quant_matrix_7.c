#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int luma[64];
extern int chroma[64];
extern double f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 64; i++) {
        int temp = 16 * f;
        if (temp < 1) {
            temp = 1;
        }
        luma[i] = temp;
        chroma[i] = temp;
    }
}
