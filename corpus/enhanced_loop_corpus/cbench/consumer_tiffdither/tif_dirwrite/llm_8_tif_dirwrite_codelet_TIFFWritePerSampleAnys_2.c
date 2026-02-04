#include <stdio.h>

#include <inttypes.h>

extern double v;
extern double *w;
extern int i;
extern int samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = v * v + 1.0;
    for (i = 0; i < samples; i += 2) {
        w[i] = temp;
        if (i + 1 < samples)
            w[i + 1] = temp;
    }
}
