#include <stdio.h>

#include <inttypes.h>

extern double v;
extern double *w;
extern int i;
extern int samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < samples * 3; i++) {
        w[i % samples] = v + (double)(i % 4) * 0.01;
    }
}
