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
    double temp_r, temp_i;
    for (j = 0; j <= fftsize / 2; j++) {
        temp_r = FFT[j].r;
        temp_i = FFT[j].i;
        spec[j] = temp_r * temp_r + temp_i * temp_i;
    }
}
