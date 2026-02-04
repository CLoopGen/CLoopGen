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
    for (i = 0; i < 5; i++) {
        lpc_n[i]           = lpc[i] * gamma_n[i];
        lpc_d[i]           = lpc[i] * gamma_d[i];
        lpc_n[i + 5]       = lpc[i + 5] * gamma_n[i + 5];
        lpc_d[i + 5]       = lpc[i + 5] * gamma_d[i + 5];
    }
}
