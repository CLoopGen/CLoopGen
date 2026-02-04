#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct EqParameter {
    float lower;
    float upper;
    float gain;
} EqParameter;

extern  float bands[];
extern float *bc;
extern EqParameter *param;
extern float fs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using index mapping array
    // Simulate indirect access via a predefined index permutation (e.g., reverse order)
    static const int indices[18] = {
        17, 16, 15, 14, 13, 12, 11, 10,
         9,  8,  7,  6,  5,  4,  3,  2,  1,  0
    };

    for (i = 0; i <= 17; i++) {
        int idx = indices[i]; // Indirect access through index remapping

        param[idx].lower = idx == 0 ? 0 : bands[idx - 1];
        param[idx].upper = idx == 17 ? fs : bands[idx];
        param[idx].gain = bc[idx];
    }
}
