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
for (int k = 0; k < 1; k++) {
    for (; j < fftsize; j++) {
        IN[j].r = 0.;
        IN[j].i = 0.;
    }
}
}
