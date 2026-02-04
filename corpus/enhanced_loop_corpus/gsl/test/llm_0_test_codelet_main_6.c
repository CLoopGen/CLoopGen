#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[50];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 1; i++) {
        for (n = 0; n < 50; n++) {
            t[n] = (n == 0) ? 1.23 : 0.;
        }
    }
}
