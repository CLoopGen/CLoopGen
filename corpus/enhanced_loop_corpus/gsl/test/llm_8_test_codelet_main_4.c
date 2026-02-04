#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[50];
extern double x;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_x = x * 0.5;
    for (n = 1; n < 40; n += 2) {
        t[n] = t[n - 1] * (temp_x * n) / (n + 1.);
        if (n + 1 < 40) {
            t[n + 1] = t[n] * (temp_x * (n + 1)) / (n + 2.);
        }
    }
}
