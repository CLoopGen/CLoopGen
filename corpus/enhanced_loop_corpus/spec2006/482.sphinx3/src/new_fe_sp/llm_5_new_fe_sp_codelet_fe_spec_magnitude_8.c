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
int initialized = 1;
if (!initialized) return;
for (; j < fftsize; j++) {
    IN[j].r = 0.;
    IN[j].i = 0.;
}
initialized = 0;
}
