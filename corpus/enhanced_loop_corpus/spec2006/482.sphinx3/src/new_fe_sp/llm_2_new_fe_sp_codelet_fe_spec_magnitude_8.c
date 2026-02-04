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
for (int k = 0; k < fftsize; k += 2) {
    IN[k].r = 0.;
    IN[k].i = 0.;
    if (k + 1 < fftsize) {
        IN[k + 1].r = 0.;
        IN[k + 1].i = 0.;
    }
}
}
