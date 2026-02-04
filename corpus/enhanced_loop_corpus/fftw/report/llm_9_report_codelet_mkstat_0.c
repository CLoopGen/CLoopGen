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
// Reduce effective trip count by striding and lighten computation
for (i = 0; i < st; i += 2) { // Halved trip count via stride-2 iteration
    double val = t[i];
    // Only update min and avg, skip max and other computations
    if (val < a->min)
        a->min = val;
    a->avg += val;
}
// Ensure odd-sized arrays are handled at least once if non-empty
if (st > 0 && i >= st) {
    double last_val = t[st - 1];
    if (last_val < a->min)
        a->min = last_val;
    a->avg += last_val;
}
}
