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
            double temp_real = y[j][i].real;
            double temp_imag = y[j][i].imag;
            x[j][i].real = temp_real;
            x[j][i].imag = temp_imag;
        }
    }
}
