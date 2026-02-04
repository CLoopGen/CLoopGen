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



void loop() {
    // Variant 2: Strided access with reversed coefficient application (indirect-like pattern)
    for (i = 10; i < 10 + low_size; i++) {
        const int center = 2 * i - 9; // Pivot around middle tap
        float sum = 0.0f;
        // Use a fixed stride and apply coefficients in reverse order across symmetric taps
        const float *coeffs = analysis_high;
        sum += input[center - 3] * coeffs[0]; // -3 offset -> coeff[0]
        sum += input[center - 1] * coeffs[1]; // -1 offset -> coeff[1]
        sum += input[center + 1] * coeffs[1]; // +1 offset -> coeff[1]
        sum += input[center + 3] * coeffs[0]; // +3 offset -> coeff[0]
        sum += input[center]     * coeffs[3]; // center   -> coeff[3]
        // Include two more symmetric pairs using analysis_high[2] at wider span
        sum += input[center - 5] * coeffs[2];
        sum += input[center + 5] * coeffs[2];
        output[i + low_size] = sum;
    }
}
