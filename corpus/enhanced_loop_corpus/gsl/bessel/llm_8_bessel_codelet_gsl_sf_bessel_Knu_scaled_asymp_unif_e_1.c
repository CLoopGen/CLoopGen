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
double t_local = t;
double tpow_local[16];
tpow_local[0] = 1.0;
for (i = 1; i < 16; i += 2) {
    tpow_local[i] = t_local * tpow_local[i - 1];
    if (i + 1 < 16) {
        tpow_local[i + 1] = t_local * tpow_local[i];
    }
}
for (i = 0; i < 16; i++) {
    tpow[i] = tpow_local[i];
}
}
