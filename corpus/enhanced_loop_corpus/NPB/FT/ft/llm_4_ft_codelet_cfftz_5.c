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
    for (i = 0; i < fftblock; i++) {
        if (!(j & 1)) {
            x[j][i].real = y[j][i].real;
            x[j][i].imag = y[j][i].imag;
        } else {
            x[j][i].real = -y[j][i].real;
            x[j][i].imag = -y[j][i].imag;
        }
    }
}
}
