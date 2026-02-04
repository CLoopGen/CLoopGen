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
for (i = 0; i < st; ++i) {
    double val = t[i];
    if (!(val >= a->min)) {
        a->min = val;
    }
    if (!(val <= a->max)) {
        a->max = val;
    }
    a->avg += val;
}
}
