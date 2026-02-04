#include <stdio.h>

#include <inttypes.h>

extern double v;
extern double *w;
extern int i;
extern int samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer = samples / 2;
    int remainder = samples % 2;
    for (i = 0; i < outer; i++) {
        w[2*i] = v;
        w[2*i + 1] = v;
    }
    if (remainder) {
        w[samples - 1] = v;
    }
}
