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
for (i = 0; i < fftblock; i++) {
    for (j = 0; j < n; j++) {
        x[j][i].real = y[j][i].real;
        x[j][i].imag = y[j][i].imag;
    }
}
}
