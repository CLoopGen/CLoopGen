#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float f_ict_params[4];
extern int csize;
extern float *src0;
extern float *src1;
extern float *src2;
extern float i0f;
extern float i1f;
extern float i2f;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < csize; i += 2) {
        // Unrolled by factor of 2 to increase computational intensity per iteration
        float temp_i0f_1, temp_i1f_1, temp_i2f_1;
        float temp_i0f_2, temp_i1f_2, temp_i2f_2;

        // First element
        temp_i0f_1 = *src0 + (f_ict_params[0] * *src2);
        temp_i1f_1 = *src0 - (f_ict_params[1] * *src1) - (f_ict_params[2] * *src2);
        temp_i2f_1 = *src0 + (f_ict_params[3] * *src1);

        src0++;
        src1++;
        src2++;

        // Second element (if within bounds)
        if (i + 1 < csize) {
            temp_i0f_2 = *src0 + (f_ict_params[0] * *src2);
            temp_i1f_2 = *src0 - (f_ict_params[1] * *src1) - (f_ict_params[2] * *src2);
            temp_i2f_2 = *src0 + (f_ict_params[3] * *src1);

            // Store second result
            *(src0++) = temp_i0f_2;
            *(src1++) = temp_i1f_2;
            *(src2++) = temp_i2f_2;
        }

        // Store first result (done after advancing pointers for second)
        *(src0 - 2) = temp_i0f_1;
        *(src1 - 2) = temp_i1f_1;
        *(src2 - 2) = temp_i2f_1;
    }
}
