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
    // Variant 1: Strided memory access with step of 2, unrolled by factor 2
    // Process two iterations per loop body, accessing elements with stride pattern
    int n = 18;
    for (i = 0; i < n; i += 2) {
        int j1 = i;
        int j2 = i + 1;

        param[j1].lower = j1 == 0 ? 0 : bands[j1 - 1];
        param[j1].upper = j1 == 17 ? fs : bands[j1];
        param[j1].gain = bc[j1];

        if (j2 < n) {
            param[j2].lower = j2 == 0 ? 0 : bands[j2 - 1];
            param[j2].upper = j2 == 17 ? fs : bands[j2];
            param[j2].gain = bc[j2];
        }
    }
}
