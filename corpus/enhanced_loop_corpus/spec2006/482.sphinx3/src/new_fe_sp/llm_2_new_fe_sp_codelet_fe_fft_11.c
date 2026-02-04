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
for (s = 0; s < N; s += 2) {
    from[s].r = in[s].r / div;
    from[s].i = in[s].i / div;
    if (s + 1 < N) {
        from[s + 1].r = in[s + 1].r / div;
        from[s + 1].i = in[s + 1].i / div;
    }
}
}
