#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex c[3];
} su3_vector;

extern su3_vector *a;
extern su3_vector *b;
extern su3_vector *c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 3; i += 2) {
    {
        double temp_real1 = (a->c[i]).real - (b->c[i]).real;
        double temp_imag1 = (a->c[i]).imag - (b->c[i]).imag;
        (c->c[i]).real = temp_real1;
        (c->c[i]).imag = temp_imag1;
        
        if (i+1 < 3) {
            double temp_real2 = (a->c[i+1]).real - (b->c[i+1]).real;
            double temp_imag2 = (a->c[i+1]).imag - (b->c[i+1]).imag;
            (c->c[i+1]).real = temp_real2;
            (c->c[i+1]).imag = temp_imag2;
        }
    }
}
}
