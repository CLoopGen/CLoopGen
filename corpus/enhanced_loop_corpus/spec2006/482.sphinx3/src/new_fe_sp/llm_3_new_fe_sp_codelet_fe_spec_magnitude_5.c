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
    int *indices = (int*)__builtin_alloca(fftsize * sizeof(int));
    for (int temp_j = 0; temp_j < fftsize; temp_j++) {
        indices[temp_j] = fftsize - 1 - temp_j;
    }
    for (j = 0; j < fftsize; j++) {
        int idx = indices[j];
        IN[idx].r = data[idx];
        IN[idx].i = 0.;
    }
}
