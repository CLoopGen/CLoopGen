#include <stdio.h>

typedef struct {
    double real;
    double imag;
} dcomplex;

extern int fftblock;
extern int n;
extern dcomplex x[256][18];
extern dcomplex y[256][18];
extern int i;
extern int j;



void loop(){
    for (j = 0; j < n; j++) {
        for (i = 1; i < fftblock; i++) {
            x[j][i].real = y[j][i-1].real;
            x[j][i].imag = y[j][i-1].imag;
        }
        if (fftblock > 0) {
            x[j][0].real = y[j][0].real;
            x[j][0].imag = y[j][0].imag;
        }
    }
}
