#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double r;
    double i;
} complex;

extern double *data;
extern int data_len;
extern int j;
extern complex *IN;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    for (j = 0; j < data_len; j += 2) {
        IN[j].r = data[j];
        IN[j].i = 0.;
        if (j + 1 < data_len) {
            IN[j+1].r = data[j+1];
            IN[j+1].i = 0.;
        }
    }
}
