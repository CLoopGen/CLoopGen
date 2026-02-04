#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lpc;
extern int i;
extern  float *gamma_n;
extern  float *gamma_d;
extern float lpc_n[10];
extern float lpc_d[10];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 10; i++) {
        if (gamma_n[i] > 0.0f) {
            lpc_n[i] = lpc[i] * gamma_n[i];
        } else {
            lpc_n[i] = 0.0f;
        }
        if (gamma_d[i] > 0.0f) {
            lpc_d[i] = lpc[i] * gamma_d[i];
        } else {
            lpc_d[i] = 0.0f;
        }
    }
}
