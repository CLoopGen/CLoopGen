#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[50];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 1; n < 50; n++) {
        if (t[n - 1] > -1.0) {
            t[n] = -t[n - 1] * (4. * (n + 1.) - 1.) / (3.1415926535897931 * 3.1415926535897931);
        } else {
            t[n] = t[n - 1];
        }
    }
}
