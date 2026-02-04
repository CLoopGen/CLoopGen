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
for (j = 0; j < n; j += 2) {
    for (i = 0; i < fftblock; i++) {
        // Strided access: process two rows at a time
        if (j + 1 < n) {
            x[j][i].real = y[j][i].real;
            x[j][i].imag = y[j][i].imag;
            x[j+1][i].real = y[j+1][i].real;
            x[j+1][i].imag = y[j+1][i].imag;
        } else {
            // Handle odd n
            x[j][i].real = y[j][i].real;
            x[j][i].imag = y[j][i].imag;
        }
    }
}
}
