#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double r;
    double i;
} complex;

extern double *spec;
extern int fftsize;
extern int j;
extern complex *FFT;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double sum = 0.0;
    for (j = 0; j <= fftsize / 2; j++) {
        spec[j] = FFT[j].r * FFT[j].r + FFT[j].i * FFT[j].i;
        sum += spec[j];
    }
    spec[0] = sum;
}
