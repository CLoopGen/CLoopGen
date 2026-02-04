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
    // Variant 2: Consecutive reverse traversal of the data array
    int idx = data_len - 1;
    for (wrap = 0; j < data_len; wrap++, j++) {
        IN[wrap].r += data[idx - j];
        IN[wrap].i += 0.;
    }
}
