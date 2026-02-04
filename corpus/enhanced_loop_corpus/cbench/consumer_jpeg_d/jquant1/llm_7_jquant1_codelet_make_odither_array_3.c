#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UINT8;

typedef int (*ODITHER_MATRIX_PTR)[16];

typedef long INT32;

extern  UINT8 base_dither_matrix[16][16];
extern ODITHER_MATRIX_PTR odither;
extern int j;
extern int k;
extern INT32 num;
extern INT32 den;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT32 local_num;
    for (j = 0; j < 16; j++) {
        for (k = 0; k < 16; k++) {
            // Eliminate reuse of 'num' variable across iterations to remove loop-carried dependency
            local_num = ((INT32)((16 * 16) - 1 - 2 * ((int)base_dither_matrix[j][k]))) * 255;
            odither[j][k] = (int)(local_num < 0 ? -((-local_num) / den) : local_num / den);
        }
        // Add artificial dependence on previous row: make odither[j][0] affect next iteration start
        if (j > 0) {
            odither[j][0] += odither[j-1][0]; // Introduce loop-carried flow dependence (RAW)
        }
    }
}
