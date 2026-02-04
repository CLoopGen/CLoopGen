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
    for (int j = 0; j < 2; j++) {
        for (i = 0; i < 10; i++) {
            lpc_n[i] = lpc[i] * gamma_n[i];
            lpc_d[i] = lpc[i] * gamma_d[i];
        }
    }
}
