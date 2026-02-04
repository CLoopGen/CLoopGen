#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double t;
extern double tpow[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i;
double acc = tpow[0];
for (i = 1; i < 32; i++) {
    acc = t * acc;
    if (i < 16) {
        tpow[i] = acc;
    }
}
}
