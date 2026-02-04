#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float analysis_high[7];
extern float *input;
extern float *output;
extern  int low_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 10; i < 10 + low_size; i++) {
        const int index_base = 2 * i;
        const float a = (index_base - 12 >= 0) ? input[index_base - 12] * analysis_high[0] : 0.0f;
        const float b = (index_base - 11 >= 0) ? input[index_base - 11] * analysis_high[1] : 0.0f;
        const float c = (index_base - 10 >= 0) ? input[index_base - 10] * analysis_high[2] : 0.0f;
        const float d = (index_base - 9  >= 0) ? input[index_base - 9]  * analysis_high[3] : 0.0f;
        const float e = (index_base - 8  >= 0) ? input[index_base - 8]  * analysis_high[2] : 0.0f;
        const float f = (index_base - 7  >= 0) ? input[index_base - 7]  * analysis_high[1] : 0.0f;
        const float g = (index_base - 6  >= 0) ? input[index_base - 6]  * analysis_high[0] : 0.0f;
        output[i + low_size] = a + b + c + d + e + f + g;
    }
}
