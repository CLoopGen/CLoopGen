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
int k;
for (k = 0; k <= fftsize / 2; k++) {
    for (j = k; j <= k; j++) {
        spec[j] = FFT[j].r * FFT[j].r + FFT[j].i * FFT[j].i;
    }
}
}
