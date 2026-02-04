#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[50];
extern double x;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 1; n < 50; n++) {
        double temp = (x * n) / (n + 1.);
        if (temp > 0.5) {
            t[n] = t[n - 1] * temp;
        } else {
            t[n] = t[n - 1] * 1.0;
        }
    }
}
