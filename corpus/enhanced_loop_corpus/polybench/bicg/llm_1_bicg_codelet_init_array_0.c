#include <stdio.h>

#include <inttypes.h>

extern int m;
extern double p[1900];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_i;
    for (outer_i = 0; outer_i < m; outer_i++) {
        i = outer_i;
        p[i] = (double)(i % m) / m;
    }
}
