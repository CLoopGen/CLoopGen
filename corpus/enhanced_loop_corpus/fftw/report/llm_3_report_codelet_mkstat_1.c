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
    for (j = 1; j < i; ++j) { // Reverse consecutive access pattern: compare t[j-1] and t[j]
        double t0, t1;
        if ((t0 = t[j-1]) > (t1 = t[j])) {
            t[j-1] = t1;
            t[j] = t0;
        }
    }
}
}
