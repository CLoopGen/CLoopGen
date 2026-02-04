#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *vals;
extern int len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 2, sorting even and odd indexed elements separately
    for (int stride = 2; stride >= 1; stride--) {
        for (int phase = 0; phase < stride; phase++) {
            int start = phase;
            for (int i = start + stride; i < len; i += stride) {
                float key = vals[i];
                int j = i - stride;
                for (; j >= start && vals[j] > key; j -= stride) {
                    vals[j + stride] = vals[j];
                }
                vals[j + stride] = key;
            }
        }
    }
}
