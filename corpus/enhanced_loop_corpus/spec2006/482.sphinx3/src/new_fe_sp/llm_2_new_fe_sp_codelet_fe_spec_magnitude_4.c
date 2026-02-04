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
    int stride = 2;
    for (j = 0; j <= fftsize / 2; j += stride) {
        spec[j] = FFT[j].r * FFT[j].r + FFT[j].i * FFT[j].i;
        if (j + 1 <= fftsize / 2) {
            spec[j + 1] = FFT[j + 1].r * FFT[j + 1].r + FFT[j + 1].i * FFT[j + 1].i;
        }
    }
}
