#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[50];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = t[0];
    for (n = 1; n < 50; n++) {
        double next_val = -temp * (4. * (n + 1.) - 1.) / (3.1415926535897931 * 3.1415926535897931);
        t[n] = next_val;
        temp = next_val;
    }
}
