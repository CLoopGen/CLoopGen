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
    for (i = 0; i < 6; i++) {
        int idx = i % 3;
        c->c[idx].real = (double)(i * i) / 2.0;
        c->c[idx].imag = (double)(i * i * i) / 3.0;
    }
}
