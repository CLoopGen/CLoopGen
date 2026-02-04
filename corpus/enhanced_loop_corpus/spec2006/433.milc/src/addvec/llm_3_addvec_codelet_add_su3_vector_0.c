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
// Variant 2: Strided memory access with stride of 2, using modulo to stay within bounds
for (i = 0; i < 3; i++) {
    {
        int idx = (i * 2) % 3; // Access index 0, then 1 (4%3=1), then 0 (again 4%3=1 -> but corrected via logic)
        // Ensures non-sequential, strided-like access pattern
        (c->c[idx]).real = (a->c[idx]).real + (b->c[idx]).real;
        (c->c[idx]).imag = (a->c[idx]).imag + (b->c[idx]).imag;
    }
}
}
