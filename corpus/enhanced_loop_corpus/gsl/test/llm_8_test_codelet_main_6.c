#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[50];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < 50; n += 2) {
        t[n] = (n == 0) ? 1.23 : 0.;
        if (n + 1 < 50) {
            t[n + 1] = 0.;
        }
    }
}
