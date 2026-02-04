#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double sum;
extern double t;
extern double y;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; t > 9.9999999999999998E-13 && i <= 1000000; i++) {
        sum += t;
        double temp = y / ((double)i * i);
        if (temp < 1e-15) continue;
        t *= temp;
    }
}
