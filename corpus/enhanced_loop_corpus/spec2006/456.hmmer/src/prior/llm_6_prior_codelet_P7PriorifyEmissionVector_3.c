#include <stdio.h>

#include <inttypes.h>

extern int num;
extern float *ret_mix;
extern int q;
extern float mix[200];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    float temp;
    for (q = 0; q < num; q++) {
        temp = mix[q];
        ret_mix[q] = temp; // Introduces temporary variable, creating a local RAW dependency
    }
}
