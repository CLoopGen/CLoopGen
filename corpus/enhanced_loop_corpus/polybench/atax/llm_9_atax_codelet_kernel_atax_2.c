#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double y[2100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double sum = 0.5;
    for (i = 0; i < n * 2; i++) {
        y[i % n] = sum;
        sum += 0.1;
        if (sum > 1.0) sum = 0.0;
    }
}
