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
    for (wrap = 0; j < data_len - (data_len % 2); wrap++, j += 2) {
        IN[wrap].r += data[j] + data[j+1];
        IN[wrap].i += 0.0;
    }
}
