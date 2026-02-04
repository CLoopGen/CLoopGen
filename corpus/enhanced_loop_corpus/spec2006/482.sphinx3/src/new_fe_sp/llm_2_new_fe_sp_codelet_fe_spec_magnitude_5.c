#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double r;
    double i;
} complex;

extern double *data;
extern int fftsize;
extern int j;
extern complex *IN;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (j = 0; j < fftsize; j += stride) {
        IN[j].r = data[j];
        IN[j].i = 0.;
        if (j + 1 < fftsize) {
            IN[j + 1].r = data[j + 1];
            IN[j + 1].i = 0.;
        }
    }
}
