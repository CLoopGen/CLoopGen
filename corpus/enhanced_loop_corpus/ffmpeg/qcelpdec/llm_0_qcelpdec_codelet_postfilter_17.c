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
    for (int i = 0; i < 1; i++) {
        for (n = 0; n < 10; n++) {
            lpc_s[n] = lpc[n] * pow_0_625[n];
            lpc_p[n] = lpc[n] * pow_0_775[n];
        }
    }
}
