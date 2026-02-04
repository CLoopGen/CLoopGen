#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float analysis_low[9];
extern float *input;
extern float *output;
extern  int low_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 10; i < 10 + low_size; i++) {
        const int idx_base = 2 * i;
        float sum = 0.0f;

        if (low_size > 5) {
            sum += input[idx_base - 14] * analysis_low[0];
            sum += input[idx_base - 13] * analysis_low[1];
            sum += input[idx_base - 12] * analysis_low[2];
            sum += input[idx_base - 11] * analysis_low[3];
            sum += input[idx_base - 10] * analysis_low[4];
            sum += input[idx_base - 9]  * analysis_low[3];
            sum += input[idx_base - 8]  * analysis_low[2];
            sum += input[idx_base - 7]  * analysis_low[1];
            sum += input[idx_base - 6]  * analysis_low[0];
        } else {
            // Fallback computation path for small low_size
            const float temp = (input[idx_base - 10] + input[idx_base - 9]) * 0.5f;
            sum = temp * analysis_low[4];
        }

        output[i] = sum;
    }
}
