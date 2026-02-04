#include <stdio.h>

#include <inttypes.h>

extern int m;
extern double p[1900];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp;
    for (i = 0; i < m; i++) {
        temp = (double)(i % m) / m;
        p[i] = temp;
    }
}
