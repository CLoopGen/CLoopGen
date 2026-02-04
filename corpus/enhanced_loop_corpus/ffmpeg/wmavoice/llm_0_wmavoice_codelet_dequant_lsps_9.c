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
    const uint8_t *t_off = &table[values[n] * num];
    double base = base_q[n], mul = mul_q[n];
    m = 0;
    for (; m < num; m++)
        lsps[m] += base + mul * t_off[m];
    table += sizes[n] * num;
}
}
