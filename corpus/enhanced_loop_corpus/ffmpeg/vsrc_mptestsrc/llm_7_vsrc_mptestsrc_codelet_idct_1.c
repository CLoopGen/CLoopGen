#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double c[64];
extern int src[64];
extern int i;
extern int j;
extern int k;
extern double tmp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double local_tmp[64];
for (i = 0; i < 8; i++) {
    for (k = 0; k < 8; k++) {
        double c_val = c[k * 8]; 
        for (j = 0; j < 8; j++) {
            int idx = 8 * i + j;
            local_tmp[idx] += c_val * src[idx]; 
            c_val = c[k * 8 + j]; 
        }
    }
}
for (i = 0; i < 64; i++) {
    tmp[i] = local_tmp[i];
}
}
