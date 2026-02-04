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
    for (n = 0; n < 5; n++) {
        lpc_s[n] = lpc[n] * pow_0_625[n] + pow_0_775[n];
        lpc_p[n] = lpc[n] * pow_0_775[n] - pow_0_625[n];
        lpc_s[n+5] = lpc[n+5] * pow_0_625[n+5] * 1.1f;
        lpc_p[n+5] = lpc[n+5] * pow_0_775[n+5] * 0.9f;
    }
}
