#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double b[2000];
extern double x[2000];
extern double y[2000];
extern int i;
extern double fn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        x[0] = 0;
        y[0] = 0;
        b[0] = 1.0 / fn / 2. + 4;
    }
    for (i = 1; i < n; i++) {
        x[i] = x[i-1]; // WAW and RAW dependency introduced
        y[i] = y[i-1]; // Loop-carried dependence (y[i] depends on y[i-1])
        b[i] = (i + 1) / fn / 2. + 4;
    }
}
