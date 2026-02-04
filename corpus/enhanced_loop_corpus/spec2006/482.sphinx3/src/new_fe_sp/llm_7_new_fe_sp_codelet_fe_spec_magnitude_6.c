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
        double val = data[j];
        IN[wrap].r = val;      // Eliminate cumulative dependency: remove any loop-carried dependence on IN[wrap-1]
        IN[wrap].i = 0.0;      // Independent of previous iterations (no loop-carried dependency)
        data[j] = val;         // WAR hazard introduced: write after potential later read in subsequent iterations if data were reused
    }
}
