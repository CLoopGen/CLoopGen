#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[50];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 2; n < 45; n += 2) {
        t[n] = -t[n - 1] * (4. * (n + 1.) - 1.) / (3.1415926535897931 * 3.1415926535897931);
        t[n-1] = t[n] * 0.5;
    }
}
