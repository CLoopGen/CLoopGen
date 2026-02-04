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
    if (div == 0.0) continue;
    from[s].r = in[s].r / div;
    from[s].i = in[s].i / div;
}
}
