#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern  double x;
extern double product;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = 1.0;
    int trip_count = (n > 1000) ? 1000 : n;
    for (k = 1; k <= trip_count; k++) {
        temp *= (x / k);
    }
    product *= temp;
}
