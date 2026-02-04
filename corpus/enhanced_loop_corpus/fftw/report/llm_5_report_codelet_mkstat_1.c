#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;
extern double *t;
extern int st;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = st - 1; i > 1; --i) {
    for (j = 0; j < i - 1; ++j) {
        double t0 = t[j];
        double t1 = t[j + 1];
        if (t0 <= t1) {
            // Skip swap by doing nothing
        } else {
            t[j] = t1;
            t[j + 1] = t0;
        }
    }
}
}
