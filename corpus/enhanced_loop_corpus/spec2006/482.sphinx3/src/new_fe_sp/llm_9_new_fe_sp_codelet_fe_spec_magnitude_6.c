#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double r;
    double i;
} complex;

extern double *data;
extern int data_len;
extern int j;
extern int wrap;
extern complex *IN;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 1;
    for (wrap = 0; j < data_len; wrap++, j++) {
        double val = data[j];
        IN[wrap].r += val * val + val;
        IN[wrap].i -= val * 0.1;
        IN[(wrap + 1) % 1024].r += val * 0.05;
    }
}
