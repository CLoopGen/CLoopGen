#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[20];
extern double sum;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 1; outer++) {
        for (n = 0; n < 20; n++) {
            double np1 = n + 1.;
            t[n] = 1. / (np1 * np1);
            sum += t[n];
        }
    }
}
