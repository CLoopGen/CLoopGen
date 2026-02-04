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
for (i = st - 1; i > 1; i -= 2) {
    for (j = 0; j < i - 2; ++j) {
        double t0 = t[j], t1 = t[j + 1], t2 = t[j + 2];
        if (t0 > t1) {
            t[j] = t1;
            t[j + 1] = t0;
        }
        if (t1 > t2) {
            t[j + 1] = t2;
            t[j + 2] = t1;
        }
    }
}
}
