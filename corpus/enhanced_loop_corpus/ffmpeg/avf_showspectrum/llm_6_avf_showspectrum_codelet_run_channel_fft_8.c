#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern float a;
extern float b;
extern float S;
extern float c;
extern FFTComplex *g;
extern FFTComplex *h;
extern int L;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_a, temp_b;
    for (int n = 0; n < L; n++) {
        float c_local = g[n].re;
        float s_local = g[n].im;
        temp_a = c_local * h[n].re - s_local * h[n].im;
        temp_b = s_local * h[n].re + c_local * h[n].im;
    }
    for (int n = 0; n < L; n++) {
        g[n].re = temp_a / L;
        g[n].im = temp_b / L;
    }
}
