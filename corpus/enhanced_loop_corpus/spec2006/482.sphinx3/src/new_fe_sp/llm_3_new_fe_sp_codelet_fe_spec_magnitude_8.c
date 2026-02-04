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
for (int k = fftsize - 1; k >= 0; k--) {
    IN[k].r = 0.;
    IN[k].i = 0.;
}
}
