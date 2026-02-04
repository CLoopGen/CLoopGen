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
    double temp_v = v;
    double temp_t = t;
    for (i = 1; temp_v != lastv; i++) {
        lastv = temp_v;
        temp_t *= x / (i * i);
        temp_v += temp_t;
    }
    v = temp_v;
    t = temp_t;
}
