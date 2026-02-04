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
    double temp_x, temp_y, temp_b;
    for (i = 0; i < n; i++) {
        temp_x = 0;
        temp_y = 0;
        temp_b = (i + 1) / fn / 2. + 4;
        x[i] = temp_x;
        y[i] = temp_y;
        b[i] = temp_b;
    }
}
