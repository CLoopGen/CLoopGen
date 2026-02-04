#include <stdio.h>

#include <inttypes.h>

extern int m;
extern double p[1900];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < m; i++)
        p[i] = p[i-1] + (double)(i % m) / m;
    if (m > 0)
        p[0] = 0.0;
}
