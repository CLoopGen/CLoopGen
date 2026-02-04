#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[50];
extern double x;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 1; n < 50; n += 2) {
        double temp1 = x / n;
        double temp2 = x / (n + 1);
        t[n] = t[n - 1] * temp1;
        if (n + 1 < 50) {
            t[n + 1] = t[n] * temp2;
        }
    }
}
