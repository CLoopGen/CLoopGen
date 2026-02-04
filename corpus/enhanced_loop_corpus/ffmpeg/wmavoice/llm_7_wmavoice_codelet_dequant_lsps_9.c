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
double prev_base = 0.0, prev_mul = 1.0;
for (n = 0; n < n_stages; n++) {
    double base = base_q[n] + prev_base;
    double mul = mul_q[n] * prev_mul;
    const uint8_t *t_off = &table[values[n] * num];
    for (m = 0; m < num; m++) {
        lsps[m] += base + mul * t_off[m];
    }
    prev_base = base;
    prev_mul = mul;
    table += sizes[n] * num;
}
}
