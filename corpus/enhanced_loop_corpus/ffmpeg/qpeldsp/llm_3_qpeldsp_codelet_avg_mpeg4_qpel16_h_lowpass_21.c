#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i++) {
        // Use strided access with precomputed offsets for better locality
        const int offsets[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
        uint8_t temp_src[17];
        uint8_t temp_dst[17];

        // Prefetch source and destination values using direct stride-based indexing
        for (int k = 0; k <= 16; k++) {
            temp_src[k] = src[offsets[k]];
            temp_dst[k] = dst[offsets[k]];
        }

        // Apply computation using local buffer to reduce memory latency
        dst[0] = ((temp_dst[0] + cm[((((temp_src[0]+temp_src[1])*20 - (temp_src[0]+temp_src[2])*6 + 
                   (temp_src[1]+temp_src[3])*3 - (temp_src[2]+temp_src[4])) + 16) >> 5)] + 1) >> 1);
        dst[1] = ((temp_dst[1] + cm[((((temp_src[1]+temp_src[2])*20 - (temp_src[0]+temp_src[3])*6 + 
                   (temp_src[0]+temp_src[4])*3 - (temp_src[1]+temp_src[5])) + 16) >> 5)] + 1) >> 1);
        dst[2] = ((temp_dst[2] + cm[((((temp_src[2]+temp_src[3])*20 - (temp_src[1]+temp_src[4])*6 + 
                   (temp_src[0]+temp_src[5])*3 - (temp_src[0]+temp_src[6])) + 16) >> 5)] + 1) >> 1);
        dst[3] = ((temp_dst[3] + cm[((((temp_src[3]+temp_src[4])*20 - (temp_src[2]+temp_src[5])*6 + 
                   (temp_src[1]+temp_src[6])*3 - (temp_src[0]+temp_src[7])) + 16) >> 5)] + 1) >> 1);
        dst[4] = ((temp_dst[4] + cm[((((temp_src[4]+temp_src[5])*20 - (temp_src[3]+temp_src[6])*6 + 
                   (temp_src[2]+temp_src[7])*3 - (temp_src[1]+temp_src[8])) + 16) >> 5)] + 1) >> 1);
        dst[5] = ((temp_dst[5] + cm[((((temp_src[5]+temp_src[6])*20 - (temp_src[4]+temp_src[7])*6 + 
                   (temp_src[3]+temp_src[8])*3 - (temp_src[2]+temp_src[9])) + 16) >> 5)] + 1) >> 1);
        dst[6] = ((temp_dst[6] + cm[((((temp_src[6]+temp_src[7])*20 - (temp_src[5]+temp_src[8])*6 + 
                   (temp_src[4]+temp_src[9])*3 - (temp_src[3]+temp_src[10])) + 16) >> 5)] + 1) >> 1);
        dst[7] = ((temp_dst[7] + cm[((((temp_src[7]+temp_src[8])*20 - (temp_src[6]+temp_src[9])*6 + 
                   (temp_src[5]+temp_src[10])*3 - (temp_src[4]+temp_src[11])) + 16) >> 5)] + 1) >> 1);
        dst[8] = ((temp_dst[8] + cm[((((temp_src[8]+temp_src[9])*20 - (temp_src[7]+temp_src[10])*6 + 
                   (temp_src[6]+temp_src[11])*3 - (temp_src[5]+temp_src[12])) + 16) >> 5)] + 1) >> 1);
        dst[9] = ((temp_dst[9] + cm[((((temp_src[9]+temp_src[10])*20 - (temp_src[8]+temp_src[11])*6 + 
                   (temp_src[7]+temp_src[12])*3 - (temp_src[6]+temp_src[13])) + 16) >> 5)] + 1) >> 1);
        dst[10] = ((temp_dst[10] + cm[((((temp_src[10]+temp_src[11])*20 - (temp_src[9]+temp_src[12])*6 + 
                    (temp_src[8]+temp_src[13])*3 - (temp_src[7]+temp_src[14])) + 16) >> 5)] + 1) >> 1);
        dst[11] = ((temp_dst[11] + cm[((((temp_src[11]+temp_src[12])*20 - (temp_src[10]+temp_src[13])*6 + 
                    (temp_src[9]+temp_src[14])*3 - (temp_src[8]+temp_src[15])) + 16) >> 5)] + 1) >> 1);
        dst[12] = ((temp_dst[12] + cm[((((temp_src[12]+temp_src[13])*20 - (temp_src[11]+temp_src[14])*6 + 
                    (temp_src[10]+temp_src[15])*3 - (temp_src[9]+temp_src[16])) + 16) >> 5)] + 1) >> 1);
        dst[13] = ((temp_dst[13] + cm[((((temp_src[13]+temp_src[14])*20 - (temp_src[12]+temp_src[15])*6 + 
                    (temp_src[11]+temp_src[16])*3 - (temp_src[10]+temp_src[16])) + 16) >> 5)] + 1) >> 1);
        dst[14] = ((temp_dst[14] + cm[((((temp_src[14]+temp_src[15])*20 - (temp_src[13]+temp_src[16])*6 + 
                    (temp_src[12]+temp_src[16])*3 - (temp_src[11]+temp_src[15])) + 16) >> 5)] + 1) >> 1);
        dst[15] = ((temp_dst[15] + cm[((((temp_src[15]+temp_src[16])*20 - (temp_src[14]+temp_src[16])*6 + 
                    (temp_src[13]+temp_src[15])*3 - (temp_src[12]+temp_src[14])) + 16) >> 5)] + 1) >> 1);

        dst += dstStride;
        src += srcStride;
    }
}
