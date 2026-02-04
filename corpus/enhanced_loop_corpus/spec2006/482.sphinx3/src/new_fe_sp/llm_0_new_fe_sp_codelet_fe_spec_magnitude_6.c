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
    for (wrap = 0; j < data_len; wrap++, j++) {
        for (int k = 0; k < 1; k++) {  // Artificially increased loop depth by nesting a single-iteration loop
            IN[wrap].r += data[j];
            IN[wrap].i += 0.;
        }
    }
}
