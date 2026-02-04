#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex e[3][3];
} su3_matrix;

typedef struct {
    complex c[3];
} su3_vector;

extern int n;
extern double c0r;
extern double c0i;
extern double c1r;
extern double c1i;
extern double c2r;
extern double c2i;
extern double br;
extern double bi;
extern double a0;
extern double a1;
extern double a2;
extern su3_matrix *a;
extern su3_vector *b;
extern su3_vector *c;
extern su3_vector *cc[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 0; n < 4; n++, a++) {
    c = cc[n];
    br = b->c[0].real;
    bi = b->c[0].imag;

    // Unroll and fuse all three rows into one dense computation to increase arithmetic intensity
    double sum0r = 0.0, sum0i = 0.0;
    double sum1r = 0.0, sum1i = 0.0;
    double sum2r = 0.0, sum2i = 0.0;

    for (int i = 0; i < 3; i++) {
        double bre = b->c[i].real;
        double bim = b->c[i].imag;

        const complex* ae_real = (const complex*)a->e[i]; // Treat rows as linear array of complex numbers

        // Process column 0
        double are0 = ae_real[0].real;
        double aim0 = ae_real[0].imag;
        sum0r += are0 * bre - aim0 * bim;
        sum0i += are0 * bim + aim0 * bre;

        // Process column 1
        double are1 = ae_real[1].real;
        double aim1 = ae_real[1].imag;
        sum1r += are1 * bre - aim1 * bim;
        sum1i += are1 * bim + aim1 * bre;

        // Process column 2
        double are2 = ae_real[2].real;
        double aim2 = ae_real[2].imag;
        sum2r += are2 * bre - aim2 * bim;
        sum2i += are2 * bim + aim2 * bre;
    }

    c->c[0].real = sum0r;
    c->c[0].imag = sum0i;
    c->c[1].real = sum1r;
    c->c[1].imag = sum2i;
    c->c[2].real = sum2r;
    c->c[2].imag = sum2i;
}
}
