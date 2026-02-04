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
    for (n = 0; n < 10; n++) {
        if (n % 2 == 0) {
            lpc_s[n] = lpc[n] * pow_0_625[n];
        } else {
            lpc_s[n] = 0.0f;
        }
        lpc_p[n] = lpc[n] * pow_0_775[n];
    }
}
