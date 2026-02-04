#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *tmp;
extern int tmpStride;
extern int srcStride;
extern  int h;
extern  int pad;
extern int i;
extern  uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern using indirect indexing via offset array
    // Simulates irregular access patterns that might occur in sparse or transformed data layouts.
    // We define a fixed set of relative offsets and use them uniformly across iterations.

    const int offsets[7] = {-2, -1, 0, 1, 2, 3, 4};  // Predefined index offsets for indirect access
    for (i = 0; i < h + 5; i++) {
        tmp[0] = (src[offsets[2]] + src[offsets[3]]) * 20 
               - (src[offsets[1]] + src[offsets[4]]) * 5 
               + (src[offsets[0]] + src[offsets[5]]) + pad;
        tmp[1] = (src[offsets[3]] + src[offsets[4]]) * 20 
               - (src[offsets[2]] + src[offsets[5]]) * 5 
               + (src[offsets[1]] + src[offsets[6]]) + pad;
        tmp[2] = (src[offsets[4]] + src[offsets[5]]) * 20 
               - (src[offsets[3]] + src[offsets[6]]) * 5 
               + (src[offsets[2]] + src[offsets[7]%7 + 5]) + pad;  // Wrap-around with distortion to simulate irregularity
        tmp[3] = (src[offsets[5]] + src[offsets[6]]) * 20 
               - (src[offsets[4]] + src[(offsets[6]+1)%7 + 5]) * 5 
               + (src[offsets[3]] + src[(offsets[6]+2)%7 + 5]) + pad;

        tmp += tmpStride;
        src += srcStride;
    }
}
