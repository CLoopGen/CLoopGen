#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double r;
    double i;
} complex;

extern int fftsize;
extern int j;
extern complex *IN;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; j < fftsize; j++) {
    if (j % 2 == 0) {
        IN[j].r = 0.;
        IN[j].i = 0.;
    } else {
        continue;
    }
}
}
