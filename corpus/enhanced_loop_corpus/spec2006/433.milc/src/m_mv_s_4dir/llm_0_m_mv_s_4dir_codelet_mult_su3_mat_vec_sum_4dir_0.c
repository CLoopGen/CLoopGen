#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex c[3];
} su3_vector;

extern su3_vector *c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int j = 0; j < 1; j++) {
    for (i = 0; i < 3; i++) {
        c->c[i].real = 0.;
        c->c[i].imag = 0.;
    }
}
}
