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
    lpc_s[0] = lpc[0] * pow_0_625[0];
    lpc_p[0] = lpc[0] * pow_0_775[0];
    for (n = 1; n < 10; n++) {
        lpc_s[n] = lpc[n] * pow_0_625[n] + lpc_s[n-1] * 0.1f;
        lpc_p[n] = lpc[n] * pow_0_775[n] + lpc_p[n-1] * 0.1f;
    }
}
