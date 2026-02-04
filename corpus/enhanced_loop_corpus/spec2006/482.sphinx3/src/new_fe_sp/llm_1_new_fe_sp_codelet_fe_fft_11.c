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
    if (N > 0) {
        s = 0;
        for (int block = 0; block < N; block += 1) {
            s = block;
            from[s].r = in[s].r / div;
            from[s].i = in[s].i / div;
        }
    }
}
