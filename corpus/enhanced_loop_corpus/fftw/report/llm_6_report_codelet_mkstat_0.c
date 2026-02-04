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
    double temp_min = a->min;
    double temp_max = a->max;
    double temp_avg = 0.0;
    for (i = 0; i < st; ++i) {
        temp_min = (t[i] < temp_min) ? t[i] : temp_min;
        temp_max = (t[i] > temp_max) ? t[i] : temp_max;
        temp_avg += t[i];
    }
    a->min = temp_min;
    a->max = temp_max;
    a->avg += temp_avg;
}
