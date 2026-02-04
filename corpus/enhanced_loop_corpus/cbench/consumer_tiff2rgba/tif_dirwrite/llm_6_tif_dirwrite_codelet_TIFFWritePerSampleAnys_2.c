#include <stdio.h>

#include <inttypes.h>

extern double v;
extern double *w;
extern int i;
extern int samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = v;
    for (i = 0; i < samples; i++) {
        w[i] = temp;
        temp = w[i]; // Introduce WAW and RAW dependency: write after write and read after write on 'temp'
    }
}
