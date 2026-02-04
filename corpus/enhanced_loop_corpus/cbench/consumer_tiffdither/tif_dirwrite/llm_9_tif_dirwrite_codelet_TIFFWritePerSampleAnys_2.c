#include <stdio.h>

#include <inttypes.h>

extern double v;
extern double *w;
extern int i;
extern int samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double sum = 0.0;
    for (i = 0; i < samples * 4; i++) {
        sum += (v + i) * (v + i);
        if (i % 4 == 0 && i / 4 < samples)
            w[i / 4] = sum / (i + 1);
    }
}
