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
    if (data_len > 0) {
        IN[0].r = data[0];
        IN[0].i = 0.;
    }
    for (j = 1; j < data_len; j++) {
        IN[j].r = data[j] + IN[j-1].r;
        IN[j].i = 0.;
    }
}
