#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double r;
    double i;
} complex;

extern int fftsize;
extern int j;
extern complex *IN;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int k = 0; k < fftsize; k++) {
    double val = 1.0 / (k + 1);
    IN[k].r = val * val;
    IN[k].i = val * 2.0;
}
}
