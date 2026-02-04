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
    for (wrap = 0; wrap < data_len && j < data_len; wrap++) {
        IN[wrap].r += data[j];
        IN[wrap].i += 0.;
        j++;  // Increment j inside the loop body to reduce loop control complexity in header
    }
}
