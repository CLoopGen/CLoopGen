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
    for (i = 0; i < fftblock; i += 2) {
        if (i + 1 < fftblock) {
            x[j][i].real = y[j][i].real;
            x[j][i].imag = y[j][i].imag;
            x[j][i+1].real = y[j][i+1].real;
            x[j][i+1].imag = y[j][i+1].imag;
        } else {
            x[j][i].real = y[j][i].real;
            x[j][i].imag = y[j][i].imag;
        }
    }
}
}
