#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[50];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 1; n < 40; n++) {
        double factor1 = 4.0 * (n + 1.0) - 1.0;
        double factor2 = 3.1415926535897931 * 3.1415926535897931;
        double temp = -t[n - 1] * factor1 / factor2;
        t[n] = temp;
        t[n] = (t[n] + t[n]) * 0.5;
    }
}
