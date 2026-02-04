#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double r;
    double i;
} complex;

extern double *data;
extern int fftsize;
extern int j;
extern complex *IN;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_r;
    for (j = 0; j < fftsize; j++) {
        temp_r = data[j];
        IN[j].r = temp_r;
        IN[j].i = 0.;
    }
}
