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
    a->avg = 0.0;
    for (i = 0; i < st; ++i) {
        double val = t[i];
        a->min = (i == 0 || val < a->min) ? val : a->min;
        a->max = (i == 0 || val > a->max) ? val : a->max;
        a->avg += val;
    }
}
