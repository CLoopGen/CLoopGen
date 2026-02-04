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
        float coeff = lpc[n];
        if (coeff > 0.5f) {
            lpc_s[n] = coeff * pow_0_625[n];
            lpc_p[n] = coeff * pow_0_775[n];
        } else {
            lpc_s[n] = coeff * 0.625f;
            lpc_p[n] = coeff * 0.775f;
        }
    }
}
