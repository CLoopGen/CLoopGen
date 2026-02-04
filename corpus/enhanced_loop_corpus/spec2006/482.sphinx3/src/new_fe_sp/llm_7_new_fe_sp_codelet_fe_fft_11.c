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
        from[0].r = in[0].r / div;
        from[0].i = in[0].i / div;
    }
    for (s = 1; s < N; s++) {
        from[s].r = in[s].r / div + from[s-1].r;
        from[s].i = in[s].i / div + from[s-1].i;
    }
}
