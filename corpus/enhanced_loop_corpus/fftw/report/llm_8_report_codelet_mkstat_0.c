#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct stats {
    double min;
    double max;
    double avg;
    double median;
};


extern struct stats *a;
extern int i;
extern double *t;
extern int st;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < st; ++i) {
    double val = t[i];
    if (val < a->min)
        a->min = val;
    if (val > a->max)
        a->max = val;
    a->avg += val * val; // Increased arithmetic intensity: square each element
}
// Additional dummy loop to increase computational load
for (j = 0; j < st / 2; ++j) {
    a->avg += (t[j] + a->min) * 0.5;
}
}
