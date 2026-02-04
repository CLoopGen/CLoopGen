#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex c[3];
} su3_vector;

su3_vector *a;
su3_vector *b;
double s;
su3_vector *c;
int i;

void init_vars() {
    const int size = 1 << 20;  // Approximately 1 million elements for ~0.01 sec runtime
    
    a = (su3_vector*)aligned_alloc(32, size * sizeof(su3_vector));
    b = (su3_vector*)aligned_alloc(32, size * sizeof(su3_vector));
    c = (su3_vector*)aligned_alloc(32, size * sizeof(su3_vector));
    
    s = 1.5;
    
    for (int idx = 0; idx < size; idx++) {
        for (int j = 0; j < 3; j++) {
            a[idx].c[j].real = (double)(idx + j) * 0.1;
            a[idx].c[j].imag = (double)(idx + j) * 0.2;
            b[idx].c[j].real = (double)(idx + j) * 0.3;
            b[idx].c[j].imag = (double)(idx + j) * 0.4;
            c[idx].c[j].real = 0.0;
            c[idx].c[j].imag = 0.0;
        }
    }
    
    i = 0;
}