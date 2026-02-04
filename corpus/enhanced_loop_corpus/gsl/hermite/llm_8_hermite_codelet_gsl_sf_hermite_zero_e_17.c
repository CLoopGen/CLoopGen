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
    for (j = 1; j < n; j += 2) {
        double temp = 2.0 * j;
        d = temp / (2.0 * x - d);
        d = (d + temp) * 0.5;
    }
}
