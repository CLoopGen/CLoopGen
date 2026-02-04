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
for (n = 0; n < n_stages; n += 2) {
    if (n + 1 < n_stages) {
        const uint8_t *t_off0 = &table[values[n] * num];
        const uint8_t *t_off1 = &table[values[n+1] * num];
        double base0 = base_q[n], mul0 = mul_q[n];
        double base1 = base_q[n+1], mul1 = mul_q[n+1];
        for (m = 0; m < num; m++) {
            lsps[m] += base0 + mul0 * t_off0[m];
            lsps[m] += base1 + mul1 * t_off1[m];
        }
        table += (sizes[n] + sizes[n+1]) * num;
    } else {
        const uint8_t *t_off = &table[values[n] * num];
        double base = base_q[n], mul = mul_q[n];
        for (m = 0; m < num; m++) {
            lsps[m] += base + mul * t_off[m];
        }
        table += sizes[n] * num;
    }
}
}
