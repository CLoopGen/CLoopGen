#include <stdio.h>

#include <inttypes.h>

extern double v;
extern double *w;
extern int i;
extern int samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < samples; i++) {
        for (j = 0; j < 1; j++) {
            w[i] = v;
        }
    }
}
