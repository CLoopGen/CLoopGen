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
    int k = fftsize - 1;
    for (j = 0; j < fftsize; j++, k--) {
        IN[j].r = data[k];
        IN[j].i = 0.;
    }
}
