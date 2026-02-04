#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *lsps;
extern int num;
extern  uint16_t *values;
extern  uint16_t *sizes;
extern int n_stages;
extern  uint8_t *table;
extern  double *mul_q;
extern  double *base_q;
extern int n;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 0; n < n_stages; n++) {
    uint16_t val = values[n];
    uint16_t size = sizes[n];
    double base = base_q[n], mul = mul_q[n];
    for (m = 0; m < num; m++) {
        int index = val * num + m;
        lsps[m] += base + mul * table[index];
    }
    table += size * num;
}
}
