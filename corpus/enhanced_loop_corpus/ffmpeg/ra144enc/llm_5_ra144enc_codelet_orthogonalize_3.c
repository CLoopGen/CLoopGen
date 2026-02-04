#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *v;
extern  float *u;
extern int i;
extern float num;
extern float den;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    num = 0.0f;
    den = 0.0f;
    for (i = 0; i < 40; i++) {
        float ui = u[i];
        float vi = v[i];
        if (ui > -1e-6f && ui < 1e-6f) continue;
        num += vi * ui;
        den += ui * ui;
    }
}
