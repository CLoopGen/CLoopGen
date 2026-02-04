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
    // Variant 2: Reverse consecutive memory access (traverse array from end to start)
    for (i = st - 1; i >= 0; --i) {
        if (t[i] < a->min)
            a->min = t[i];
        if (t[i] > a->max)
            a->max = t[i];
        a->avg += t[i];
    }
}
