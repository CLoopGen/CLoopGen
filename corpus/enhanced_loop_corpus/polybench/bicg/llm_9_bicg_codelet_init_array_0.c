#include <stdio.h>

#include <inttypes.h>

extern int m;
extern double p[1900];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = 0; i < m; i += step) {
        if (i + 1 < m) {
            p[i] = (double)(i % m) / m;
            p[i+1] = (double)((i+1) % m) / m;
        } else {
            p[i] = (double)(i % m) / m;
        }
    }
}
