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
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < st; i += 2) {
        if (t[i] < a->min)
            a->min = t[i];
        if (t[i] > a->max)
            a->max = t[i];
        a->avg += t[i];

        // Handle the second element in the stride if within bounds
        if (i + 1 < st) {
            if (t[i + 1] < a->min)
                a->min = t[i + 1];
            if (t[i + 1] > a->max)
                a->max = t[i + 1];
            a->avg += t[i + 1];
        }
    }
}
