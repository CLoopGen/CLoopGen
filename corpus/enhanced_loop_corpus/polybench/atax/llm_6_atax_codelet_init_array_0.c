#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double x[2100];
extern int i;
extern double fn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp;
    for (i = 0; i < n; i++) {
        temp = 1 + (i / fn);
        x[i] = temp;
    }
}
