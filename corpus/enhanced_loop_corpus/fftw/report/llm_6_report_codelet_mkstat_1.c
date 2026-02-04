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
        double prev = t[0];
        for (j = 1; j < i - 1; ++j) {
            double current = t[j];
            if (prev > current) {
                t[j - 1] = current;
                t[j] = prev;
            }
            prev = current;
        }
        if (i > 2) {
            double last = t[i - 2];
            if (t[i - 3] > last) {
                t[i - 2] = t[i - 3];
                t[i - 3] = last;
            }
        }
    }
}
