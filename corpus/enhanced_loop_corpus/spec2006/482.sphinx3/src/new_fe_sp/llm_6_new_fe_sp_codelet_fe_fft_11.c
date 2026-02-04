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
    complex temp;
    for (s = 0; s < N; s++) {
        temp.r = in[s].r / div;
        temp.i = in[s].i / div;
        from[s].r = temp.r;
        from[s].i = temp.i;
    }
}
