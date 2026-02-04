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
    for (n = 0; n < 10; n += 2) {
        float temp1 = lpc[n] * pow_0_625[n];
        float temp2 = lpc[n] * pow_0_775[n];
        lpc_s[n] = temp1;
        lpc_p[n] = temp2;

        if (n + 1 < 10) {
            lpc_s[n+1] = lpc[n+1] * pow_0_625[n+1] * 1.05f;
            lpc_p[n+1] = lpc[n+1] * pow_0_775[n+1] * 0.95f;
        }
    }
}
