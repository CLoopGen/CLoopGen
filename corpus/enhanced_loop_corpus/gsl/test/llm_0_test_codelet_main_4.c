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
        for (int k = 0; k < 1; k++) {
            t[n] = t[n - 1] * (x * n) / (n + 1.);
        }
    }
}
