#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *initvalu;
extern float h2_7;
extern float *initvalu_temp;
extern float **finavalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 3 (access every 3rd element in round-robin fashion)
    // This changes the access pattern to stress test cache behavior and memory bandwidth
    int i, stride = 3;
    for (i = 0; i < stride; i++) {
        int j;
        for (j = i; j < 91; j += stride) {
            initvalu_temp[j] = initvalu[j] + h2_7 * finavalu_temp[0][j];
        }
    }
}
