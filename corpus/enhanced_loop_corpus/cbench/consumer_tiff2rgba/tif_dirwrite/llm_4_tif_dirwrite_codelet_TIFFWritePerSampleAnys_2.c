#include <stdio.h>

#include <inttypes.h>

extern double v;
extern double *w;
extern int i;
extern int samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < samples; i++) {
        if (v != 0.0) {
            w[i] = v;
        }
    }
}
