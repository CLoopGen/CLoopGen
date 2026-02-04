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
    if (j % 3 == 0) {
        for (i = 0; i < fftblock; i++) {
            x[j][i].real = y[j][i].real * 2.0;
            x[j][i].imag = y[j][i].imag * 2.0;
        }
    } else {
        for (i = 0; i < fftblock; i++) {
            x[j][i].real = y[j][i].real;
            x[j][i].imag = y[j][i].imag;
        }
    }
}
}
