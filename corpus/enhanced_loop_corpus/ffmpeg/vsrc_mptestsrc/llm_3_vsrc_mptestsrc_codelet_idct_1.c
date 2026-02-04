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
for (i = 0; i < 8; i++) {
    int dst_idx = 8 * i;
    int src_idx_base = 8 * i;
    for (k = 0; k < 8; k++) {
        double c_val = c[k * 8]; 
        for (j = 0; j < 8; j++) {
            tmp[dst_idx + j] += c_val * src[src_idx_base + j];
            c_val = c[k * 8 + j + 1]; 
        }
    }
}
}
