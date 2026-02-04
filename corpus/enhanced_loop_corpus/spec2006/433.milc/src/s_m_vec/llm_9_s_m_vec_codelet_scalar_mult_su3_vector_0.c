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
extern double s;
extern su3_vector *c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 6; i++) { // Increased trip count from 3 to 6
        int idx = i % 3;
        double temp_real = s * a->c[idx].real;
        double temp_imag = s * a->c[idx].imag;
        // Accumulate scaled values twice per element
        if (i < 3) {
            c->c[idx].real = temp_real;
            c->c[idx].imag = temp_imag;
        } else {
            c->c[idx].real += temp_real; // Additional operation: fused multiply-add effect
            c->c[idx].imag += temp_imag;
        }
    }
}
