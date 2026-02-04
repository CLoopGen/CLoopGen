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
for (i = 0; i < 2; i++) {
    {
        double temp_real_0 = (a->c[0]).real + (b->c[0]).real;
        double temp_imag_0 = (a->c[0]).imag + (b->c[0]).imag;
        double temp_real_1 = (a->c[1]).real + (b->c[1]).real;
        double temp_imag_1 = (a->c[1]).imag + (b->c[1]).imag;
        double temp_real_2 = (a->c[2]).real + (b->c[2]).real;
        double temp_imag_2 = (a->c[2]).imag + (b->c[2]).imag;

        (c->c[0]).real = temp_real_0;
        (c->c[0]).imag = temp_imag_0;
        (c->c[1]).real = temp_real_1;
        (c->c[1]).imag = temp_imag_1;
        (c->c[2]).real = temp_real_2;
        (c->c[2]).imag = temp_imag_2;
    }
}
}
