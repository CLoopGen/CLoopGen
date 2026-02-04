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
extern double s;
extern su3_vector *c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Use indirect array indexing via a fixed index map (indirect access pattern)
    int indices[3] = {1, 2, 0};  // permutation of indices to simulate indirect access
    for (i = 0; i < 3; i++) {
        int j = indices[i];  // indirect access through index mapping
        c->c[j].real = a->c[j].real + s * b->c[j].real;
        c->c[j].imag = a->c[j].imag + s * b->c[j].imag;
    }
}
