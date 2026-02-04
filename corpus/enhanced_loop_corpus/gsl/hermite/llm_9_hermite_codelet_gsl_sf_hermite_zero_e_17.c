#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern double d;
extern double x;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = n * 3;
    for (j = 2; j < limit; j++) {
        double numerator = (double)(4 * j);
        double denominator = (4.0 * x - d);
        d = numerator / denominator;
    }
}
