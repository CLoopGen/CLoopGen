#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[6];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = 0.0;
    for (i = 0; i < 6; ++i) {
        temp += t[i];  // Introduce RAW dependency: each iteration reads t[i] and accumulates into temp
        t[i] = temp;   // Introduce WAW dependency: t[i] is written after being read in accumulation
    }
}
