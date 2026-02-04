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
    double temp_r = 0.0;
    for (wrap = 0; j < data_len; wrap++, j++) {
        temp_r += data[j];
        IN[wrap].r = temp_r;  // WAW dependency introduced: each iteration writes IN[wrap].r, depends on previous write via temp_r
        IN[wrap].i = 0.0;
    }
}
