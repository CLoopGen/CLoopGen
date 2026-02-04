#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double x[2000];
extern double z[2000];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp[2000];
    for (i = 0; i < n; i++) {
        temp[i] = z[i];
    }
    for (i = 0; i < n; i++) {
        x[i] = x[i] + temp[i];
    }
}
