#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[50];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < 50; n++) {
        if (n == 0) {
            t[n] = 1.23;
        } else {
            t[n] = 0.;
        }
    }
}
