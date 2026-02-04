#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x;
extern double v;
extern double lastv;
extern double t;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= 50 && (v - lastv) > 1e-9; i += 2) {
        lastv = v;
        double temp = x / (i * i);
        t *= temp;
        v += t;
        if (i + 1 <= 50) { // Simulate unrolled body without actual unrolling syntax
            lastv = v;
            temp = x / ((i + 1) * (i + 1));
            t *= temp;
            v += t;
        }
    }
}
