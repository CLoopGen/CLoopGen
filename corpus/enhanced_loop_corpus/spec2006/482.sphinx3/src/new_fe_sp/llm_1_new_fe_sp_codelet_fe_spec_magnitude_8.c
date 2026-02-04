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
for (int outer = 0; outer < fftsize; outer++) {
    if (j >= fftsize) break;
    IN[j].r = 0.;
    IN[j].i = 0.;
    j++;
}
}
