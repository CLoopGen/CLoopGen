#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < n; i += 2) {
        if (i + 1 < n) {
            double val1 = vec[i];
            double val2 = vec[i + 1];
            if (val1 < vec[best] && val1 <= val2)
                best = i;
            else if (val2 < vec[best])
                best = i + 1;
        } else {
            if (vec[i] < vec[best])
                best = i;
        }
    }
}
