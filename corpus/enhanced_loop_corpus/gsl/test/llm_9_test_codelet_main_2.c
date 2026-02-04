#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[50];
extern double x;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 1; n < 25; n++) {
        double xn = x / n;
        t[n] = t[n - 1] * xn;
        t[49 - n] = t[48 - n] * xn; // Symmetric update from both ends
    }
}
