#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *restrict v1;
extern float *restrict v2;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < len; i += 2) {
        float t = v1[i] - v2[i];
        v1[i] += v2[i];
        v2[i] = t;
        
        // Process next element if within bounds
        if (i + 1 < len) {
            float t_next = v1[i+1] - v2[i+1];
            v1[i+1] += v2[i+1];
            v2[i+1] = t_next;
        }
    }
}
