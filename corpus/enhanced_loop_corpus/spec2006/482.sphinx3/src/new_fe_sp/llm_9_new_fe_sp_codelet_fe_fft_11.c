#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double r;
    double i;
} complex;

extern complex *in;
extern int N;
extern int s;
extern complex *from;
extern double div;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (s = 0; s < N; s++) {
        double real = in[s].r / div;
        double imag = in[s].i / div;
        from[s].r = real * real - imag * imag;
        from[s].i = 2.0 * real * imag;
    }
}
