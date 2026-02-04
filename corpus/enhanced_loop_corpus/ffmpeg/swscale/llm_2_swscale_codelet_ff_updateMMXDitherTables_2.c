#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int vLumFilterSize;
extern  int16_t **tmpY;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element in reverse order)
    for (; i < vLumFilterSize; i += 2) {
        if (i - 2 >= 0) {
            tmpY[i] = tmpY[i - 2];
        }
    }
}
