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
if (st > 0) {
    // Handle first element outside the loop to reduce effective iterations
    if (t[0] < a->min)
        a->min = t[0];
    if (t[0] > a->max)
        a->max = t[0];
    a->avg += t[0];

    for (i = 1; i < st; ++i) { // Reduced effective loop body complexity by peeling one iteration
        if (t[i] < a->min)
            a->min = t[i];
        if (t[i] > a->max)
            a->max = t[i];
        a->avg += t[i];
    }
}
}
