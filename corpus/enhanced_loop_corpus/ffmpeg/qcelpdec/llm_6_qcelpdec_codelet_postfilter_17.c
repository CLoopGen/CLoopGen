#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lpc;
extern  float pow_0_775[10];
extern  float pow_0_625[10];
extern float lpc_s[10];
extern float lpc_p[10];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_s[10];
    float temp_p[10];
    for (n = 0; n < 10; n++) {
        temp_s[n] = lpc[n] * pow_0_625[n];
        temp_p[n] = lpc[n] * pow_0_775[n];
    }
    for (n = 0; n < 10; n++) {
        lpc_s[n] = temp_s[n];
        lpc_p[n] = temp_p[n];
    }
}
